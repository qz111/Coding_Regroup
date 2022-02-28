#include "PlmDatabaseId.h"
#include "PlmDBUtils.hpp"
	
#include <iostream>

namespace
{
	HRESULT QueryExternalPlmId(PlmIdentifier iPlmId, ExternalPlmId* opExtPlmId)
	//CODE REVIEW: The argument ExternalPlmId* opExtPlmId should be better shared_ptr<ExternalPlmId>, because the normal pointer can point to 
	//unexpected when the local shared_ptr goes out of scope and the reference count of the shared_ptr is reduced to 0 and the memory released.
	{
		std::shared_ptr<ExternalPlmId> extPlmId;
		if (PlmDBUtils::QueryDBId(iPlmId.plmType, iPlmId.plmName, iPlmId.plmRevision, extPlmId) == E_FAIL)
		{
			return E_FAIL;
		}

		if (!extPlmId->IsValid())
		{
			return E_FAIL;
		}
		opExtPlmId = extPlmId.get();
		return S_OK;
	}

	HRESULT QueryPlmId(ExternalPlmId* ipExtPlmId, PlmIdentifier& oPlmId)
	// CODE REVIEW: The normal pointer ExternalPlmId* ipExtPlmId should be shared_ptr, or the pointee of the normal pointer will be deleted.
	// Because the local shared_ptr goes out of scope out of the function and the memory of the pointee will be released which is still useful in other part of code.
	{
		return PlmDBUtils::QueryDBProperties(std::shared_ptr<ExternalPlmId>(ipExtPlmId), oPlmId.plmType, oPlmId.plmName, oPlmId.plmRevision);
	}
}

PlmDatabaseId::PlmDatabaseId(): _pExtPlmId(nullptr)
{
}

PlmDatabaseId::PlmDatabaseId(ExternalPlmId* iExtPlmId): _pExtPlmId(iExtPlmId)
// CODE REVIEW: According to the implementation of the QueryPlmId, the pointer ExternalPlmId* iExtPlmId is danggling after this query.
// It is a risk for further use of this pointer.
{
	QueryPlmId(_pExtPlmId, _plmId);
}

PlmDatabaseId::PlmDatabaseId(const PlmIdentifier iPlmId) : _plmId(iPlmId)
// CODE REVIEW: According to the implementation of the QueryExternalPlmId, the initialisation of pointer _pExtPlmId failed. It is still nullptr.
{
	QueryExternalPlmId(_plmId, _pExtPlmId);
}

PlmDatabaseId::PlmDatabaseId(std::string& iString): _pExtPlmId (new ExternalPlmId(iString))
{
	QueryPlmId(_pExtPlmId, _plmId);
}


PlmDatabaseId::PlmDatabaseId(const PlmDatabaseId& other)
{
	_plmId = other._plmId;
	_pExtPlmId = other._pExtPlmId;
}

PlmDatabaseId::PlmDatabaseId(PlmDatabaseId&& other)
{
	_plmId = std::move(other._plmId);
	_pExtPlmId = std::move(other._pExtPlmId);
}

PlmDatabaseId::~PlmDatabaseId()
{}

PlmDatabaseId& PlmDatabaseId::operator=(const PlmDatabaseId& other)
{
	this->_plmId = other._plmId;
	this->_pExtPlmId = other._pExtPlmId;
	return *this;
}

PlmDatabaseId& PlmDatabaseId::operator=(PlmDatabaseId&& other)
{
	this->_pExtPlmId = std::move(other._pExtPlmId);
	this->_plmId = std::move(other._plmId);
	return *this;
}

bool PlmDatabaseId::operator==(const PlmDatabaseId& other) const
{
	return (_pExtPlmId == other._pExtPlmId);
}

bool PlmDatabaseId::operator!=(const PlmDatabaseId& other) const
{
	return !this->operator==(other);
}

bool PlmDatabaseId::operator<(const PlmDatabaseId& other) const
{
	return _pExtPlmId < other._pExtPlmId;
}

bool PlmDatabaseId::IsValid()
{
	return _pExtPlmId->IsValid();
}

PlmIdentifier PlmDatabaseId::ToPlmId() const
{
	return _plmId;
}

ExternalPlmId* PlmDatabaseId::ToExternalPlmId() const
{
	return _pExtPlmId;
}

std::string PlmDatabaseId::ToString()
{
	return _pExtPlmId->ToString();
}

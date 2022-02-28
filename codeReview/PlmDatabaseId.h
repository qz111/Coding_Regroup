#include <string>

class ExternalPlmId;

struct PlmIdentifier
{
	std::string plmType;
	std::string plmName;
	std::string plmRevision;
};

class PlmDatabaseId
{
public:
	PlmDatabaseId();

	PlmDatabaseId(ExternalPlmId* iExtPlmId);
	PlmDatabaseId(const PlmIdentifier iPlmId);
	PlmDatabaseId(std::string& iPlmIdString);

	~PlmDatabaseId();

	PlmDatabaseId(const PlmDatabaseId& other);
	PlmDatabaseId(PlmDatabaseId&& other);

	PlmDatabaseId& operator=(const PlmDatabaseId& other);
	PlmDatabaseId& operator=(PlmDatabaseId&& other);

	bool operator==(const PlmDatabaseId& other) const;
	bool operator!=(const PlmDatabaseId& other) const;
	bool operator<(const PlmDatabaseId& other) const;

	bool IsValid();

	PlmIdentifier ToPlmId() const;
	ExternalPlmId* ToExternalPlmId() const;

	std::string ToString();

private:
	PlmIdentifier _plmId;
	ExternalPlmId* _pExtPlmId;
	//CODE REVIEW: better use shared_ptr because of the smart pointer usage in the Query util code
};

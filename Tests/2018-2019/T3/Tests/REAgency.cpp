#include "REAgency.h"
#include <algorithm>
REAgency::REAgency(): catalogItems(PropertyTypeItem("", "","", 0)) {
	//do nothing!
}

REAgency::REAgency(vector<Property*> properties): catalogItems(PropertyTypeItem("", "","", 0)) {
	this->properties = properties;
}

void REAgency::addProperty(Property* property) {
	this->properties.push_back(property);
}

void REAgency::addProperties(vector<Property*> properties) {
	this->properties = properties;
}

vector<Property*> REAgency::getProperties() const{
	return this->properties;
}

PropertyTypeItem REAgency::getTypeItem(string address, string postalCode, string typology) {
	PropertyTypeItem itemNotFound("", "", "", 0);
	BSTItrIn<PropertyTypeItem> it(catalogItems);
	while (!it.isAtEnd())
	{
		if( it.retrieve().getAddress() == address && it.retrieve().getPostalCode() == postalCode && it.retrieve().getTypology() == typology) {
			PropertyTypeItem pti(it.retrieve().getAddress(), it.retrieve().getPostalCode(), it.retrieve().getTypology(), 0);
			pti.setItems(it.retrieve().getItems());
			return pti;
		}
		it.advance();
	}
	return itemNotFound;
}

void REAgency::addTypeItem(Property* property) {
	PropertyTypeItem itemNotFound("", "","", 0);
	PropertyTypeItem pti(property->getAddress(), property->getPostalCode(), property->getTypology(), property->	getPrice());
	PropertyTypeItem ptiX = catalogItems.find(pti);
	if(ptiX == itemNotFound) {
		pti.addItems(property);
		this->catalogItems.insert(pti);
	}
	else {
		this->catalogItems.remove(ptiX);
		ptiX.addItems(property);
		this->catalogItems.insert(ptiX);
	}
	properties.push_back(property);
}

BST<PropertyTypeItem> REAgency::getTypeItems() const {
	return this->catalogItems;
}

vector<ClientRecord> REAgency::getClientRecords() const {
	vector<ClientRecord> records;
	HashTabClientRecord::const_iterator it1 = this->listingRecords.begin();
	HashTabClientRecord::const_iterator it2 = this->listingRecords.end();
	for(; it1 != it2; it1++) {
			records.push_back(*it1);
	}
	return records;
}

void REAgency::setClientRecords(vector<ClientRecord>& crs) {
	for(unsigned int i = 0; i < crs.size(); i++) {
		listingRecords.insert(crs[i]);
	}

}

priority_queue<Client> REAgency::getClientProfiles() const {
	return clientProfiles;
}
void REAgency::setClientProfiles(priority_queue<Client>& profiles) {
	clientProfiles = profiles;
}

void REAgency::generateCatalog() {
	for(auto prop : properties){
        PropertyTypeItem item(prop->getAddress(),
                         prop->getPostalCode(),
                         prop->getTypology(),
                         0);
	    PropertyTypeItem found = catalogItems.find(item);

	    if(!found.getAddress().empty()){
            catalogItems.remove(found);
            found.addItems(prop);
            catalogItems.insert(found);
        }
	    else{
	        item.addItems(prop);
	        catalogItems.insert(item);
	    }

	}
}

vector<Property*> REAgency::getAvailableProperties(Property* property) const {
	vector<Property*> temp;

    PropertyTypeItem toFind(property->getAddress(),
                            property->getPostalCode(),
                            property->getTypology(),0);

	PropertyTypeItem found = catalogItems.find(toFind);

	for(auto item : found.getItems())
	    if(get<0>(item->getReservation()) == nullptr) temp.push_back(item);

	return temp;
}

bool REAgency::reservePropertyFromCatalog(Property* property, Client* client, int percentage) {
    PropertyTypeItem toFind(property->getAddress(),
                            property->getPostalCode(),
                            property->getTypology(),0);

    PropertyTypeItem found = catalogItems.find(toFind);

    if(found.getAddress().empty()) return false;

    for(auto ptr : found.getItems()){
        if(get<0>(ptr->getReservation()) == NULL){
            ptr->setReservation(tuple<Client*,int>(client, (100-percentage)/100.0*ptr->getPrice()));
            return true;
        }
    }

	return false;
}

void REAgency::addClientRecord(Client* client) {
	listingRecords.insert(ClientRecord(client));
}

void REAgency::deleteClients() {
    for (auto it = listingRecords.begin(); it != listingRecords.end();) {
        if(it->getClientPointer()->getVisitedProperties().empty()){
            it = listingRecords.erase(it);
            continue;
        }
        it++;
    }
}

//
// TODO: Part III - Priority Queue
//
void REAgency::addBestClientProfiles(const vector<Client>candidates, int min) {

    for (const auto& client : candidates) {
        if(client.getVisitedProperties().size() == 0) continue;

        if((float )std::count_if(properties.begin(), properties.end(),
                                 [client](Property* ptr){
                                     Client * c = get<0>(ptr->getReservation());
                                     return client.getName() == c->getName() &&
                                            client.getEMail() == c->getEMail();
                                 }) / client.getVisitedProperties().size() > (float)min)
            clientProfiles.push(client);
    }


}

vector<Property*> REAgency::suggestProperties() {
	vector<Property*> tempProperties;

	priority_queue<Client> copy;

	copy = clientProfiles;

	while (!copy.empty()){
	    Client temp = copy.top();
	     copy.pop();

        if(!get<0>(temp.getVisiting()).empty()){
            Property * currMin = nullptr;

            for(auto ptr : properties){
                if(currMin == nullptr ||
                    abs(stoi(get<3>(temp.getVisiting())) - stoi(ptr->getPostalCode())) < stoi(get<3>(temp.getVisiting())) - stoi(currMin->getPostalCode()))
                        currMin = ptr;
            }
            if(currMin != nullptr)
                tempProperties.push_back(currMin);
        }
	}

	return tempProperties;
}

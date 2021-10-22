#include "remove_duplicates.h"

#include "search_server.h"
#include <iostream>
#include <string>
#include <set>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::set;
using std::string;

void RemoveDuplicates(SearchServer& search_server) {
    const map<int, set<string>> documents = search_server.GetDocuments();

    map<set<string>, int> documents_inverting;
    for (const auto& [id, words] : documents) { // 1. инициализация обратного словаря
        if (documents_inverting.count(words)) {
            cout << "Found duplicate document id " << id << endl;
            search_server.RemoveDocument(id);
        }
        else {
            documents_inverting[words] = id;
        }
    }
}

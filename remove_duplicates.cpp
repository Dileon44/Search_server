#include "remove_duplicates.h"

#include <iostream>
#include <string>
#include <set>
#include <map>

using std::map;
using std::cout;
using std::endl;
using std::set;
using std::string;

void RemoveDuplicates(SearchServer& search_server) {
    const map<int, set<string>> documents = search_server.GetDocuments();
    map<set<string>, int> documents_inverting;
    
    for (auto it = documents.rbegin(); it != documents.rend(); ++it) { 
        documents_inverting[it->second] = it->first;
    }
    
    map<int, set<string>> documents_time;
    for (const auto [set_words, id] : documents_inverting) {
        documents_time[id] = set_words;
    }
    
    for (const auto [id, _] : documents) {
        if (!documents_time.count(id)) {
            cout << "Found duplicate document id " << id << endl;
            search_server.RemoveDocument(id);
        }
    }
}

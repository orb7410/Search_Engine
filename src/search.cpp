#include <stdexcept>
#include <unordered_map>
#include <algorithm>

#include "search.hpp"

namespace se {

namespace {

void removeDuplicateResults(std::vector<QueryResult>& a_results)
{
    // store url counts across internal vectors
	std::unordered_map<std::string, int> urlMap;
	std::vector<std::tuple<std::string, std::string, uint32_t>> finalResults;

    // count the occurrence of each url across internal vectors
    for (const auto& innerVec : a_results) {
        for (const auto& tuple : innerVec) {
            const std::string& url = std::get<1>(tuple);
            ++urlMap[url];
        }
    }

    // Iterate over each internal vector
    auto outerIt = a_results.begin();
    while (outerIt != a_results.end()) {
        auto& innerVec = *outerIt;

        // iterate over each tuple in the inner vector
        auto innerIt = innerVec.begin();
        while (innerIt != innerVec.end()) {
            const std::string& url = std::get<1>(*innerIt);
            if (urlMap[url] == 1) {
				// remove not duplicated url
                innerIt = innerVec.erase(innerIt);
            }
            else {
                ++innerIt;
            }
        }

        if (innerVec.empty()) {
			// remove the entire inner vector
            outerIt = a_results.erase(outerIt);
        }
        else {
            ++outerIt;
        }
    }
}

QueryResult mergeFinalResults(const std::vector<QueryResult>& a_results) {
    std::unordered_map<std::string, uint32_t> mergedMap;

    for (const QueryResult& queryResult : a_results) {
        for (const auto& tuple : queryResult) {
            const std::string& url = std::get<1>(tuple);
            uint32_t counter = std::get<2>(tuple);

            mergedMap[url] += counter;
        }
    }

    QueryResult mergedResult;

	// filling the result vector
    for (auto itMap = mergedMap.begin(); itMap != mergedMap.end(); ++itMap) {
        const std::string& url = itMap->first;
        uint32_t counter = itMap->second;

        // find the corresponding title for the URL
        std::string title;
        for (const QueryResult& queryResult : a_results) {
            for (const auto& tuple : queryResult) {
                if (std::get<1>(tuple) == url) {
                    title = std::get<0>(tuple);
                    break;
                }
            }
            if (!title.empty()) {
                break;
            }
        }
        mergedResult.push_back(std::make_tuple(title, url, counter));
    }

	std::sort(mergedResult.begin(), mergedResult.end(), [](const auto& a_counter1, const auto& a_counter2) {
        return std::get<2>(a_counter1) > std::get<2>(a_counter2);
    });

    return mergedResult;
}

} // namespace

Search::Search(ISearch& a_searcher)
: m_searcher(a_searcher)
{
}

QueryResult Search::executeSearch(Query const& a_query) const{
    QueryResult resultVecOfTuple;
    std::vector<QueryResult> resultsAllWords;

    std::vector<std::string> terms = a_query.getQuery();
    auto it = terms.begin();
    while(it != terms.end()){
        std::string& word = *it;
        resultVecOfTuple = m_searcher.getWordData(word);

        resultsAllWords.push_back(resultVecOfTuple);
        ++it;
    }
	if(terms.size() > 1) {
    	removeDuplicateResults(resultsAllWords);
	}

    return mergeFinalResults(resultsAllWords);;
}

} // namespace se


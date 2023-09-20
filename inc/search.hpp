#pragma once

#include <string>
#include <vector>
#include <tuple>

#include "query.hpp"
#include "isearch.hpp"

namespace se {

//tuple of : title, url , counter
using QueryResult = std::vector<std::tuple<std::string, std::string, uint32_t>> ;

class Search {
public:
    Search() = delete;
    explicit Search(ISearch& a_searcher);

    QueryResult executeSearch(Query const& a_query) const;


private:
    ISearch& m_searcher;
};

} // namespace s


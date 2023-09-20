#pragma once

#include <string> // std::string
#include <vector> // std::vector

#include "string_utils.hpp"

namespace se {

class Query {
public:
    Query() = delete;
    explicit Query(const std::string& a_term);
    Query(Query const& a_other) = default;
    Query& operator=(const Query& a_other) = default;
    ~Query() = default;

    const std::vector<std::string>& getQuery() const;
	const std::string& getTerm() const;
private:
    void normalizeQuery(const std::string& a_term);

private:
    std::vector<std::string> m_queryVec;
	std::string m_term;
};

} // namespace se


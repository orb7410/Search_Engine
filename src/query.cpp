#include <sstream> // std::istringstream

#include "query.hpp" // Current header

namespace se {

Query::Query(const std::string& a_term)
: m_queryVec()
, m_term()
{
	normalizeQuery(a_term);

	for(std::string& word : m_queryVec) {
		m_term += word + " ";
	}
	//remove last space
	m_term = m_term.substr(0, m_term.size() - 1);
}

void Query::normalizeQuery(const std::string& a_term)
{
    if (a_term.empty()) {
        return;
    }

    std::string word = a_term;
    word = toLowercase(a_term);

    // stream class that reads from a string
    std::istringstream iss(a_term);

    while (iss >> word) {
        if (word.length() < 3 || !isalpha(word[0])) {
            continue;
        }
		m_queryVec.push_back(word);
    }
}

const std::vector<std::string>& Query::getQuery() const {
    return m_queryVec;
}

const std::string& Query::getTerm() const {
    return m_term;
}

}// namespace se


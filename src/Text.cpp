#include "../include/Text.hpp"


void ItalicText::render(const std::string& data) const noexcept {
    std::cout << "<i>";
    m_text->render(data);
	std::cout << "</i>";
}

void BoldText::render(const std::string& data) const noexcept {
	std::cout << "<b>";
    m_text->render(data);
    std::cout << "</b>";
}

void Paragraph::render(const std::string& data) const noexcept {
	std::cout << "<p>";
    m_text->render(data);
    std::cout << "</p>";
}

void Reversed::render(std::string data) noexcept {
    std::reverse(data.begin(), data.end());
    m_text->render(data);
}

void Link::render(const std::string& href, const std::string& data) const noexcept {
	std::cout << "<a href=" << href << ">";
    m_text->render(data);
    std::cout << "</a>";
}

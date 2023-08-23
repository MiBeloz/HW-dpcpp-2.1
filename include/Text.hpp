#pragma once

#include <iostream>
#include <string>
#include <algorithm>


class Reversed;
class Link;

class Text {
public:
	Text() = default;
	~Text() {}
	
	Text(const Text& other) = delete;
	Text(Text&& other) noexcept = delete;
	Text& operator=(const Text& other) = delete;
	Text& operator=(Text&& other) noexcept = delete;
	
	virtual void render(const std::string& data) const noexcept {
		std::cout << data;
    }
};

class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : m_text(text) {}
	
protected:
    Text* m_text;
};

class ItalicText final : public DecoratedText {
public:
	ItalicText(Reversed*) = delete;
	ItalicText(Link*) = delete;
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const noexcept override;
};

class BoldText final : public DecoratedText {
public:
	BoldText(Reversed*) = delete;
	BoldText(Link*) = delete;
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const noexcept override;
};

class Paragraph final : public DecoratedText {
public:
	Paragraph(Reversed*) = delete;
	Paragraph(Link*) = delete;
	explicit Paragraph(Text* text) : DecoratedText(text) {}
	void render(const std::string& data) const noexcept override;
};

class Reversed final : public DecoratedText {
public:
	Reversed(Link*) = delete;
	explicit Reversed(Text* text) : DecoratedText(text) {}
	void render(std::string data) noexcept;
};

class Link final : public DecoratedText {
public:
	Link(Reversed*) = delete;
	explicit Link(Text* text) : DecoratedText(text) {}
	void render(const std::string& href, const std::string& data) const noexcept;
};

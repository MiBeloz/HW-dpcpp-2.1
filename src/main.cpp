#include "../include/main.hpp"


int main() {
#if WIN32
	setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
	
	std::cout << "\tСтруктурные шаблоны: Proxy, Decorator, Adapter\n\n" << std::endl;

	std::cout << "Класс ItalicText" << std::endl;
	auto text_block_italictext = new ItalicText(new Text());
	text_block_italictext->render("Hello world");
	std::cout << std::endl << std::endl;

	std::cout << "Класс BoldText" << std::endl;
	auto text_block_boldtext = new BoldText(new Text());
	text_block_boldtext->render("Hello world");
	std::cout << std::endl << std::endl;

	std::cout << "Класс Paragraph" << std::endl;
	auto text_block_paragraph = new Paragraph(new Text());
	text_block_paragraph->render("Hello world");
	std::cout << std::endl << std::endl;

	std::cout << "Класс Reversed" << std::endl;
	auto text_block_reversed = new Reversed(new Text());
	text_block_reversed->render("Hello world");
	std::cout << std::endl << std::endl;

	std::cout << "Класс Link" << std::endl;
	auto text_block_link = new Link(new Text());
	text_block_link->render("netology.ru", "Hello world");
	std::cout << std::endl << std::endl << std::endl;


	std::cout << "\tВызов нескольких конструкторов классов\n" << std::endl;

	std::cout << "Классы ItalicText, BoldText, Paragraph" << std::endl;
	auto text_block_ibp = new ItalicText(new BoldText(new Paragraph(new Text())));
	text_block_ibp->render("Hello world");
	std::cout << std::endl << std::endl;

	std::cout << "Классы Reversed, BoldText, Paragraph" << std::endl;
	auto text_block_rbp = new Reversed(new BoldText(new Paragraph(new Text())));
	text_block_rbp->render("Hello world");
	std::cout << std::endl << std::endl;

	std::cout << "Классы Link, BoldText, ItalicText" << std::endl;
	auto text_block_lbi = new Link(new BoldText(new ItalicText(new Text())));
	text_block_lbi->render("netology.ru", "Hello world");
	std::cout << std::endl << std::endl << std::endl;


	std::cout << "Вызовы типа:\n"
		"\tnew ItalicText(new BoldText(new Link(new Text())));\n"
		"\tnew ItalicText(new BoldText(new Reversed(new Text())));\n"
		"запрещены в классах." << std::endl;
	
	std::cin.get();
	return 0;
}
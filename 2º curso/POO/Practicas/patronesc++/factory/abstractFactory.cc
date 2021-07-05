#include <iostream>

class Button
{
public:
	virtual void paint() = 0;
};
 
class WinButton : public Button 
{
public:
	void paint (){
		std::cout << " Window Button \n";
       }
};
 
class MacButton : public Button 
{
public:
	void paint (){
		std::cout << " Mac Button \n";
       }
};

class ScrollBar 
{
public:
	virtual void paint() = 0;
};
 
class WinScrollBar : public ScrollBar 
{
public:
	void paint (){
		std::cout << " Window ScrollBar \n";
       }
};
 
class MacScrollBar : public ScrollBar {
public:

	void paint (){
		std::cout << " Mac ScrollBar \n";
       }
};


class GUIFactory // Abstract Factory
{
public:
	virtual Button* createButton () = 0;
	virtual ScrollBar* createScrollBar () = 0;
};
 
class WinFactory : public GUIFactory 
{
public:
	Button* createButton (){
		return new WinButton;
	}
	ScrollBar* createScrollBar (){
		return new WinScrollBar;
	}
};
 
class MacFactory : public GUIFactory 
{
public:
	Button* createButton (){
		return new MacButton;
	}
	ScrollBar* createScrollBar (){
		return new MacScrollBar;
	}
};
 
int main()
{
	GUIFactory* guiFactory;
	Button *btn;
	ScrollBar *sb;

	guiFactory = new MacFactory;
	btn = guiFactory->createButton(); //Botón Mac
	btn -> paint();
	sb = guiFactory->createScrollBar(); //Scroll Mac
	sb -> paint();

    delete guiFactory;
	delete btn;
	delete sb;
	
	guiFactory = new WinFactory;
	btn = guiFactory->createButton();
	btn -> paint();
	sb = guiFactory->createScrollBar();
	sb -> paint();

    delete guiFactory;
	delete btn;
	delete sb;
	return 0;
}
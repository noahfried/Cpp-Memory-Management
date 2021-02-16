#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot& other) {
    	std::cout << "ChatBot Copy Constructor" << std::endl;
        _chatLogic = other._chatLogic;

        _rootNode = other._rootNode;
        _image = new wxBitmap();
        *_image = *other._image;
//         _chatLogic->SetChatbotHandle(this);
    }
    ChatBot(const ChatBot&& other) {
    	std::cout << 'ChatBot Move Constructor' << std::endl;
        _image = other._image;
        
    }
    ChatBot& operator=(const ChatBot& other) {
    	std::cout << 'ChatBot Copy Assignment Operator' << std::endl;
        if (this != &other) {
          delete[] other._chatLogic;
          delete[] other._rootNode;
//           delete[] *other._image;
//           std::copy(other._chatLogic, other._rootNode, *other._image);
		_currentNode = other._currentNode;
        _rootNode = other._rootNode;
        _chatLogic = other._chatLogic;
        _image = new wxBitmap();
        *_image = *other._image;
//         _chatLogic->SetChatbotHandle(this);
        }
        return *this;
    }
    ChatBot& operator=(const ChatBot&& other) {
    	std::cout << 'ChatBot Move Assignment Operator' << std::endl;
    	if (this != &other) {
        	delete[] _chatLogic;
            delete[] _rootNode;
//             delete[] *_image;
            
            _chatLogic = other._chatLogic;
            _rootNode = other._rootNode;
            _currentNode = other._currentNode;
//             *_image = other.*_image;
			_image = new wxBitmap();
            *_image = *other._image;
            
           delete[] other._chatLogic;
            delete[] other._rootNode;
            delete[] other._image;
        }
    }
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
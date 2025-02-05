#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <memory>
#include <vector>
#include <string>
#include "chatgui.h"
#include "chatbot.h"
#include "graphnode.h"

class ChatLogic
{
private:
    // data handles (owned)
    std::vector<std::unique_ptr<GraphNode>> _nodes;

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */
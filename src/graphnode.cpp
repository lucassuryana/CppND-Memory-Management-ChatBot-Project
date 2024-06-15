#include "graphnode.h"
#include "graphedge.h"

GraphNode::GraphNode(int id)
    : _id(id)
{
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    // Clear the parent and child edges vectors
    _parentEdges.clear();
    _childEdges.clear();

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// CHANGES: Implement function to add edge to child node using unique_ptr
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

// CHANGES: Implement function to move chatbot to this node
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

// CHANGES: Implement function to move chatbot to a new node
void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////
    return (_childEdges[index]).get();
    ////
    //// EOF STUDENT CODE
}


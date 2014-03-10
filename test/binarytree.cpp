#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define Element char
#define STACK_SIZE 50

// struct tree definition
typedef struct Node{
	Element 	data;
	struct Node *lChild;
	struct Node *rChild;
}Node, *Tree;

//---------------------------------------------------------------------
// struct stack Definition
typedef struct Stack{
	Node 		**node_data;
	int 		min_stack;
	int 		max_stack;
	int 		top;
}Stack;

void stack_init(Stack **stack)
{
	(*stack) = (Stack*)malloc(sizeof(Stack));
	(*stack)->min_stack = 0;
	(*stack)->max_stack = 50;
	(*stack)->top		 = 0;
	(*stack)->node_data = (Node**)malloc((*stack)->max_stack* sizeof(Node*));
}

bool stack_push(Stack *stack, Node *node)
{
	if (stack->top >= stack->max_stack)
	{
		std::cout << "The Stack is full!!" << std::endl;
		return false;
	}
	
	stack->node_data[stack->top++] = node;

	return true;
}

Node* stack_pop(Stack *stack)
{
	if (stack->top > 0)	
	{
		return stack->node_data[--stack->top];
	}
}

bool stack_empty(Stack *stack)
{
	if (stack->top == stack->min_stack)
	  return true;
	return false;
}
//---------------------------------------------------------------------



// struct queue Definition
typedef struct Queue{
	Node 	 	*node_data;
	struct Queue *next;
}Queue;

// construct the tree
void treeNodeConstructor(Tree &root, Element *data, int index)
{
	Element e = data[index];
	if (e == '#')
	{
		root = NULL;
	}
	else
	{
		root = (Node*)malloc(sizeof(Node));
		root->data = e;
		treeNodeConstructor(root->lChild, data, ++index);
		treeNodeConstructor(root->rChild, data, ++index);
	}
}

void depthFirstSearch(Tree root)
{
	Stack *nodeStack;
	stack_init(&nodeStack);
	stack_push(nodeStack, root);

	Node *node;
	while (!stack_empty(nodeStack))
	{
		node = stack_pop(nodeStack);
		printf("%c\t", node->data);
		if (node->lChild)
		{
			stack_push(nodeStack, node->lChild);
		}

		if (node->rChild)
		{
			stack_push(nodeStack, node->rChild);	
		}
	}
}

void breadthFirstSearch(Tree root)
{
}

// test
int main() 
{
    //上图所示的二叉树先序遍历序列,其中用'#'表示结点无左子树或无右子树
    Element data[15] = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#'};
    Tree tree;
    treeNodeConstructor(tree, data, 0);
    printf("深度优先遍历二叉树结果: ");
    depthFirstSearch(tree);
    printf("\n\n广度优先遍历二叉树结果: ");
    breadthFirstSearch(tree);
    return 0;
}

#endif


//
//  main.cpp
//  Balancer
//
//  Created by Coral Hernandez on 10/7/19.
//  Copyright © 2019 COSC2430Hw2. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct node{
	char open;
	node* next;
};

class stack{
	node* top;
	public:
	stack(){top = NULL;}
	bool isEmpty();
	void peek(char&);
	bool isEncapsulator(char);
	bool isClosed(char);
	void compare(char, bool&);
	void balancer(string);
	~stack();
	char pop();
	void push(char);
	void print();
};

bool stack::isEmpty(){
	if(top == NULL)
		return true;
	return false;	
}

void stack::peek(char& e){
	e  = top->open;
}

bool stack::isEncapsulator(char b){
	if(b == '{' || b == '(' || b =='[' || b =='}' || b == ')' || b == ']')
		return true;
	return false;	
}

bool stack::isClosed(char b){
	if(b == '{' || b == '(' || b =='[')
		return false;
	return true;	
}

void stack::compare(char c, bool  &b){
	char e;
	peek(e);
	switch(c){
		case ')':
			if(e == '(')
				pop();
			else
				b = false;
			break;
		case '}':
			if(e == '{')
				pop();
			else
				b = false;
			break;
		case ']':
			if(e == '[')
				pop();
			else
				b = false;
			break;
		}
}

char stack::pop(){
	char t;
	node *temp = top;
	t = temp->open;
	top = temp->next;
	delete temp;
	return t;
}

void stack::push(char b){
	node* temp = new node;
	temp->open = b;
	temp->next = top;
	top = temp;
}

stack::~stack(){
	while(!isEmpty()){
		pop();
	}
}

void stack::balancer(string e){
	bool t = true;
	
	for(char c: e){
		if(isEncapsulator(c)){
			if(isClosed(c)){
				compare(c,t);
			} else{
				push(c);
			}
		}
	}
	if(!isEmpty()){
		cout << "Equation not balanced." << endl;
	}else{
		cout << "Equation is balanced." << endl;
	}
}

void stack::print(){
	node * cu = top;
	while(cu != NULL){
		cout << cu->open << " ";
	}
	cout << endl;
}

int main() {
	string eq = "(3+1)*(2^(8*7+10)]";
	stack O;
	
	O.balancer(eq);

	return 0;
}

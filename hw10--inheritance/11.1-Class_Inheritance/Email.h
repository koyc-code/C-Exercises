#pragma once
#include <iostream>
#include <string>
#include "Document.h"
using namespace std;
class Email:public Document {//three ways to inheritance:public,protected,private
private:
	string sender;
	string recipient;
	string title;
public:
	Email() {
		this->setText("");
		sender = "";
		recipient = "";
		title = "";
	}
	Email(string text, string sender, string recipient, string title) {
		this->setText(text);
		this->sender = sender;
		this->recipient = recipient;
		this->title = title;
	}
	void operator=(Email rhs) {
		this->setText(rhs.getText());
		this->sender = rhs.sender;
		this->recipient = rhs.recipient;
		this->title = rhs.title;
	}
	void setSender(string sender) {
		this->sender = sender;
	}
	string getSender() {
		return this->sender;
	}
	void setRecipient(string recipient) {
		this->recipient = recipient;
	}
	string getRecipient() {
		return this->recipient;
	}
	void setTitle(string title) {
		this->title = title;
	}
	string getTitle() {
		return this->title;
	}
};
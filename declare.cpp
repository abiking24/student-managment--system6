#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace std;

class Node {
public:
    int roll_no;
    string name, course, quali, phone_no, address;
    Node* next;
};

class LinkedList {
private:
    Node* head;

    void saveToFile() {
        ofstream file("Students.txt");
        Node* temp = head;
        while(temp != NULL) {
            file << temp->roll_no << "\n"
                 << temp->name << "\n"
                 << temp->course << "\n"
                 << temp->quali << "\n"
                 << temp->phone_no << "\n"
                 << temp->address << "\n\n";
            temp = temp->next;
        }
        file.close();
    }

public:
    LinkedList() : head(NULL) {
        loadFromFile();
    }

    ~LinkedList() {
        Node* current = head;
        while(current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void loadFromFile() {
        ifstream file("Students.txt");
        if(!file) return;

        string line;
        while(getline(file, line)) {
            if(line.empty()) continue;

            Node* new_node = new Node();
            try { new_node->roll_no = stoi(line); }
            catch(...) { delete new_node; continue; }

            getline(file, new_node->name);
            getline(file, new_node->course);
            getline(file, new_node->quali);
            getline(file, new_node->phone_no);
            getline(file, new_node->address);

            while(file.peek() == '\n') file.ignore();

            new_node->next = NULL;
            if(head == NULL) {
                head = new_node;
            } else {
                Node* temp = head;
                while(temp->next != NULL) temp = temp->next;
                temp->next = new_node;
            }
        }
        file.close();
    }

    bool isIDUnique(int id) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->roll_no == id) return false;
            temp = temp->next;
        }
        return true;
    }

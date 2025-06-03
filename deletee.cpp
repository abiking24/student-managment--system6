
    void deleteRecord() {
        if(head == NULL) {
            cout << "\nList is Empty!\n";
            return;
        }
        int id;
        cout << "\nEnter Student ID to Delete: ";
        cin >> id;

        if(head->roll_no == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            saveToFile();
            cout << "\nRecord Deleted Successfully!\n";
            return;
        }

        Node* prev = head;
        Node* current = head->next;
        while(current != NULL) {
            if(current->roll_no == id) {
                prev->next = current->next;
                delete current;
                saveToFile();
                cout << "\nRecord Deleted Successfully!\n";
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "\nStudent Not Found!\n";
    }

    void sortByID() {
        if (head == NULL || head->next == NULL) return;

        bool swapped;
        Node *ptr1, *lptr = NULL;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->roll_no > ptr1->next->roll_no) {
                    // Swap data
                    swap(ptr1->roll_no, ptr1->next->roll_no);
                    swap(ptr1->name, ptr1->next->name);
                    swap(ptr1->course, ptr1->next->course);
                    swap(ptr1->quali, ptr1->next->quali);
                    swap(ptr1->phone_no, ptr1->next->phone_no);
                    swap(ptr1->address, ptr1->next->address);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

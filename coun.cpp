 void count() {
        int count = 0;
        Node* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "\nTotal Records: " << count << endl;
    }

    void update() {
        if(head == NULL) {
            cout << "\nList is Empty!\n";
            return;
        }
        int id;
        cout << "\nEnter Student ID to Update: ";
        cin >> id;

        Node* temp = head;
        while(temp != NULL) {
            if(temp->roll_no == id) {
                cout << "\nEnter New Details:\n";
                cout << "Name: ";
                cin.ignore();
                getline(cin, temp->name);
                cout << "Course: ";
                getline(cin, temp->course);
                cout << "Qualification: ";
                getline(cin, temp->quali);
                cout << "Phone No: ";
                getline(cin, temp->phone_no);
                cout << "Address: ";
                getline(cin, temp->address);

                saveToFile();
                cout << "\nRecord Updated Successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\nStudent Not Found!\n";
    }
    
   void search() {
        if(head == NULL) {
            cout << "\nList is Empty!\n";
            return;
        }
        int id;
        cout << "\nEnter Student ID to Search: ";
        cin >> id;

        Node* temp = head;
        while(temp != NULL) {
            if(temp->roll_no == id) {
                cout << "\nStudent Found!\n";
                cout << "ID: " << temp->roll_no << endl
                     << "Name: " << temp->name << endl
                     << "Course: " << temp->course << endl
                     << "Qualification: " << temp->quali << endl
                     << "Phone: " << temp->phone_no << endl
                     << "Address: " << temp->address << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "\nStudent Not Found!\n";
    }

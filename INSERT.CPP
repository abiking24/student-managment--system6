 void insert() {
        Node* new_node = new Node();
        int id;

        do {
            cout << "\nEnter Student ID: ";
            cin >> id;
            if(!isIDUnique(id)) {
                cout << "This ID already exists. Please enter a unique ID.\n";
            }
        } while(!isIDUnique(id));

        new_node->roll_no = id;

        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, new_node->name);
        cout << "Enter Course: ";
        getline(cin, new_node->course);
        cout << "Enter Qualification: ";
        getline(cin, new_node->quali);
        cout << "Enter Phone No: ";
        getline(cin, new_node->phone_no);
        cout << "Enter Address: ";
        getline(cin, new_node->address);
        new_node->next = NULL;

        if(head == NULL) {
            head = new_node;
        } else {
            Node* temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp->next = new_node;
        }
        saveToFile();
        cout << "\nRecord Inserted Successfully!\n";
    }
    
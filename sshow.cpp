
    void showAll() {
        if(head == NULL) {
            cout << "\nList is Empty!\n";
            return;
        }

        sortByID(); // Automatically sort before showing

        Node* temp = head;
        cout << "\nAll Student Records (Sorted by ID):\n";
        cout << "----------------------------------------\n";
        while(temp != NULL) {
            cout << "ID: " << temp->roll_no << endl
                 << "Name: " << temp->name << endl
                 << "Course: " << temp->course << endl
                 << "Qualification: " << temp->quali << endl
                 << "Phone: " << temp->phone_no << endl
                 << "Address: " << temp->address << endl
                 << "----------------------------------------\n";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    int choice;

    do {
        system("cls");
        cout << "\nSTUDENT MANAGEMENT SYSTEM";
        cout << "\n1. Insert Record";
        cout << "\n2. Search Record";
        cout << "\n3. Count Records";
        cout << "\n4. Update Record";
        cout << "\n5. Delete Record";
        cout << "\n6. Show All Records";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: list.insert(); break;
            case 2: list.search(); break;
            case 3: list.count(); break;
            case 4: list.update(); break;
            case 5: list.deleteRecord(); break;
            case 6: list.showAll(); break;
            case 7: exit(0);
            default: cout << "\nInvalid Choice!";
        }

        cout << "\nPress any key to continue...";
        getch();
    } while(true);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct item {
    char code[10];
    char desc[30];
    long qty;
    double price;
    long reordqty;
};

struct supplier {
    char code[10];
    char name[50];
    char address[100]; // Combined address field
    char state[20];    // State field
    long pin;
    char phone[13];
};

struct customer {
    char code[10];
    char name[50];
    char address[100]; // Combined address field
    char state[20];    // State field
    long pin;
    char phone[13];
   
};

struct transaction {
    char transType; // 'P' for Purchase, 'S' for Sale
    char itemcode[10];
    char itemdesc[30];
    long qty;
    double totalPrice;
};

// Function declarations
int createitem();
void customizeitem();
int createsupplier();
void customizeSupplierDetails();
int createCustomer();
void customizeCustomerDetails();
int recordPurchaseTransaction();
int recordSaleTransaction();
int displayInventory();
int displayCustomer();
int displaySupplier();
int displaySaleTransactions();
int displayPurchaseTransactions();
int create_report_item(struct item rec);
int create_report_supplier(struct supplier rec);
int create_report_customer(struct customer rec);
int create_report_PurchaseTransaction(struct transaction rec);
int create_report_SaleTransaction(struct transaction rec);
int writeItemtofile(struct item rec);
int writeSuppliertoFile(struct supplier rec);
int writeCustomertoFile(struct customer rec);
int writePurchaseTransactionToFile(struct transaction rec);
int writeSaleTransactionToFile(struct transaction rec);
int updateItemQuantity(const char *itemCode, long quantityChange);
void askDisplayOption(char option);
int deleteItem();
int deleteSupplier();
int deleteCustomer();
int deletePurchaseTransaction();
int deleteSaleTransaction();
void updateInventory(const char *itemCode, long qty, char transType) ;
void writeDeletedItemToFile(const char *deletedItem);
void writeDeletedCustomerToFile(const struct customer *deletedCustomer);
void writeDeletedSupplierToFile(const struct supplier *deletedSupplier);

int main() {
    char optchoice;
    char option;
    char displayOption;

    optchoice = 'Y';

    while (optchoice == 'Y' || optchoice == 'y') {
        
        option = ' ';

        // Ask whether to display information or perform an action
        printf("\n\n\n");
        printf("          Electro Shock Pro      \n");
        printf("\n\n");
        printf("                 MENU           \n");
        printf("         ====================   \n\n");
        printf("        D. Display Information\n");
        printf("        A. Perform Action\n");
        printf("        X. Delete Records\n");
        printf("\n\n\n");
        printf(" Option (D/A/X): ");
        scanf(" %c", &displayOption);

        if (displayOption == 'D' || displayOption == 'd') {
            // Display information
            printf("\nWhat information would you like to display?\n");
            printf("1. Inventory\n");
            printf("2. Supplier\n");
            printf("3. Customer\n");
            printf("4. Purchase Transactions\n");
            printf("5. Sale Transactions\n");
            
            // Ask for the specific display option
            printf(" \nEnter option (1-5): ");
            while ((option = getchar()) == '\n');

            switch (option) {
                case '1':
                    displayInventory();
                    break;

                case '2':
                    displaySupplier();
                    break;

                case '3':
                    displayCustomer();
                    break;

                case '4':
                    displayPurchaseTransactions();
                    break;

                case '5':
                    displaySaleTransactions();
                    break;

                default:
                    printf("Invalid option. Please choose again.\n");
                    break;
            }
        } else if (displayOption == 'A' || displayOption == 'a') {
            // Perform action
            printf("\n\n");
            printf("          MENU           \n");
            printf("  ====================   \n\n");
            printf(" 1.  Enter a New Item in Item Master \n\n");
            printf(" 2.  Customize Item in Item Master \n\n");
            printf(" 3.  Create a New Supplier \n\n");
            printf(" 4.  Customize Supplier details \n\n");
            printf(" 5.  Create a New Customer \n\n");
            printf(" 6.  Customize Customer details \n\n");
            printf(" 7.  Record a Purchase Transaction \n\n");
            printf(" 8.  Record a Sale Transaction \n\n");
            printf("\n\n");
            printf(" Option :  ");

            while ((option = getchar()) == '\n');

            switch (option) {
                case '1':
                    createitem();
                    break;
                
                case '2': 
                    customizeitem();
                    break;

                case '3':
                    createsupplier();
                    break;
                
                case '4':
                    customizeSupplierDetails();
                    break;

                case '5':
                    createCustomer();
                    break;

                case '6':
                    customizeCustomerDetails();
                    break;

                case '7':
                    recordPurchaseTransaction();
                    break;

                case '8':
                    recordSaleTransaction();
                    break;

                default:
                    printf("Invalid option. Please choose again.\n");
                    break;
            }
        } else if(displayOption=='X' || displayOption=='x')  {
                 printf("What information would you like to delete?\n");
            printf("1. Inventory\n");
            printf("2. Supplier\n");
            printf("3. Customer\n");
            printf("4. Purchase Transactions\n");
            printf("5. Sale Transactions\n");
            printf("\n\n");
            printf(" Enter option (1-5): ");
            while ((option = getchar()) == '\n');

            switch (option) {
                case '1':
                    deleteItem();
                    break;

                case '2':
                    deleteSupplier();
                    break;

                case '3':
                    deleteCustomer();
                    break;

                case '4':
                    deletePurchaseTransaction();
                    break;

                case '5':
                    deleteSaleTransaction();
                    break;

                default:
                    printf("Invalid option. Please choose again.\n");
                    break;
            }
        }
    }


        printf(" Would you like to Continue(Y/N):  ");
        option=getchar();
        while ((optchoice = getchar()) == '\n');

        // Clear the input buffer
        while (getchar() != '\n');
    

    return 0;
}


int createitem() {
    struct item newitem;
    char ch;

    printf("\n\n\n  ITEM CREATION \n\n\n");
    scanf("%c", &ch);
    printf(" Item Code : ");
    fgets(newitem.code, 9, stdin);
    newitem.code[strlen(newitem.code) - 1] = '\0';
    printf(" Item Desc : ");
    fgets(newitem.desc, 29, stdin);
    for (int i = 0; i < strlen(newitem.desc); i++) {
        newitem.desc[i] = toupper((unsigned char)newitem.desc[i]);
    }

    newitem.desc[strlen(newitem.desc) - 1] = '\0';
    printf(" Item Quantity : ");
    scanf("%ld", &newitem.qty);
    printf(" Item Price : ");
    scanf("%lf", &newitem.price);
    printf(" Item Reorder Quantity : ");
    scanf("%ld", &newitem.reordqty);
    scanf("%c", &ch);

    printf(" Adding Item... \n");
    printf("\n %10s  %30s  %5ld  %4.2f  %4ld \n", newitem.code, newitem.desc, newitem.qty, newitem.price, newitem.reordqty);
    writeItemtofile(newitem);
    create_report_item(newitem);
    

    return 0;
}

int writeItemtofile(struct item rec) {
    FILE *wp, *rp;
    struct item readrec;
    int stat = 1; // Initializing stat

    rp = fopen("item_master.dat", "rb");

    while (stat == 1) {
        stat = fread(&readrec, sizeof(rec), 1, rp);
        if (stat == 1 && strncmp(readrec.code, rec.code, sizeof(readrec.code)) == 0) {
            printf(" The item code exists in the database \n");
            fclose(rp); 
            return -1;
        }
    }
    fclose(rp);

    wp = fopen("item_master.dat", "ab");
    fwrite(&rec, sizeof(rec), 1, wp);
    printf(" Added Item... \n");
    fclose(wp);
    return 0;
}

int updateItemQuantity(const char *itemCode, long quantityChange) {
    FILE *file;
    struct item currentItem;

    // Open the file in read and write mode
    file = fopen("item_master.dat", "rb+");
    if (file == NULL) {
        printf("Error opening item_master.dat file for updating quantity.\n");
        return -1;
    }

    // Find the item with the specified itemCode
    while (fread(&currentItem, sizeof(struct item), 1, file) == 1) {
        if (strcmp(currentItem.code, itemCode) == 0) {
            // Update the quantity
            currentItem.qty += quantityChange;

            // Move the file pointer to the beginning of the item's record
            fseek(file, -sizeof(struct item), SEEK_CUR);

            // Write the updated item back to the file
            if (fwrite(&currentItem, sizeof(struct item), 1, file) != 1) {
                printf("Error updating item quantity.\n");
            }

            break; // Item found and updated, exit the loop
        }
    }

    fclose(file);
    return 0;
}

int create_report_item(struct item rec) {
    FILE *rp;
    struct item prec;
    int stat;
    int itemcounter;
    FILE *file = fopen("item_master.txt", "w");

    rp = fopen("item_master.dat", "rb");
    fprintf(file, "__________________________ELCETRO SHOCK PRO ELECTRONIC SHOP_________________________\n\n");
    fprintf(file, "\n %-15s %-30s %-10s %-10s %-15s \n", "Item Code", "Item Description", "Quantity", "Sale Price", "Reorder Qty");
    
    itemcounter = 0;
    stat = fread(&prec, sizeof(rec), 1, rp);
    
    while (stat == 1) {
        fprintf(file, " %-15s %-30s %-10ld %-10.2f %-15ld \n", prec.code, prec.desc, prec.qty, prec.price, prec.reordqty);
        itemcounter += 1;
        stat = fread(&prec, sizeof(rec), 1, rp);
    }

    printf("\n\n Report Created with %d Records \n", itemcounter);
    fclose(rp);
    fclose(file);
}


int createsupplier() {
    struct supplier newsupplier;
    char ch;

    printf("\n\n\n  SUPPLIER CREATION \n\n\n");
    scanf("%c", &ch);
    printf(" Supplier Code : ");
    fgets(newsupplier.code, 9, stdin);
    newsupplier.code[strlen(newsupplier.code) - 1] = '\0';

    printf(" Supplier Name : ");
    fgets(newsupplier.name, 49, stdin);
    newsupplier.name[strlen(newsupplier.name) - 1] = '\0';

    printf(" Supplier Address : ");  // Modified prompt for the address
    fgets(newsupplier.address, 99, stdin);  // Combine address line 1 and line 2
    newsupplier.address[strlen(newsupplier.address) - 1] = '\0';

    printf(" Supplier State  : ");
    fgets(newsupplier.state, 29, stdin);
    newsupplier.state[strlen(newsupplier.state) - 1] = '\0';

    printf(" Supplier Pin : ");
    scanf("%ld", &newsupplier.pin);
    
    // Clear the input buffer
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    printf(" Supplier Phone No  : ");
    fgets(newsupplier.phone, 11, stdin);
    newsupplier.phone[strlen(newsupplier.phone) - 1] = '\0';
    
    printf(" Adding Supplier... \n");
    printf("\n %10s  %50s", newsupplier.code, newsupplier.name);
   
   writeSuppliertoFile(newsupplier);
   create_report_supplier(newsupplier);

    return 0;
}


int writeSuppliertoFile(struct supplier rec) {
    FILE *wp, *rp;
    struct supplier readrec;
    int stat;

    rp = fopen("supplier_master.dat", "ab");
    if (rp == NULL) {
        printf("Error opening supplier_master.dat for reading.\n");
        return -1;
    }

    stat = fread(&readrec, sizeof(struct supplier), 1, rp);
    while (stat == 1) {
        // Use memcmp for comparing fixed-size character arrays
        if (memcmp(readrec.code, rec.code, sizeof(rec.code)) == 0) {
            printf("The Supplier code exists in the database.\n");
            fclose(rp);
            return -1;
        }
        stat = fread(&readrec, sizeof(struct supplier), 1, rp);
    }

    fclose(rp);

    // Open the file in append mode to add the new supplier
    wp = fopen("supplier_master.dat", "ab");
    if (wp == NULL) {
        printf("Error opening supplier_master.dat for writing.\n");
        return -1;
    }

    fwrite(&rec, sizeof(struct supplier), 1, wp);
    printf("Added Supplier...\n");

    fclose(wp);

    return 0;
}


int create_report_supplier(struct supplier rec) {
    FILE *rp;
    struct supplier prec;
    int stat;
    int itemcounter;
    FILE *file = fopen("supplier.txt", "a");  // Change mode to "a" to append to the file

    if (file == NULL) {
        printf("Error opening supplier.txt for writing.\n");
        return -1;
    }

    rp = fopen("supplier_master.dat", "rb");

    if (rp == NULL) {
        printf("Error opening supplier_master.dat for reading.\n");
        fclose(file);
        return -1;
    }


    fprintf(file, "\n %-15s %-30s %-100s %-30s %-6s %-15s \n",
            "Supplier Code", "Supplier Name", "Address", "State", "Pin", "Phone No");

    itemcounter = 0;
    stat = fread(&prec, sizeof(rec), 1, rp);
    while (stat == 1) {
        fprintf(file, " %-15s %-30s %-100s %-30s %-6ld %-15s \n",
                prec.code, prec.name, prec.address, prec.state, prec.pin, prec.phone);
        itemcounter += 1;
        stat = fread(&prec, sizeof(rec), 1, rp);
    }

    printf("\n\n Report Created with %d Records \n", itemcounter);

    fclose(rp);
    fclose(file);

    return 0;
}

int createCustomer() {
    struct customer newCustomer;
    char ch;

    printf("\n\n\n  CUSTOMER CREATION \n\n\n");
    scanf("%c", &ch);
    printf(" Customer Code : ");
    fgets(newCustomer.code, 14, stdin);
    newCustomer.code[strlen(newCustomer.code) - 1] = '\0';

    printf(" Customer Name : ");
    fgets(newCustomer.name, 29, stdin);
    newCustomer.name[strlen(newCustomer.name) - 1] = '\0';

    printf(" Customer Address : "); 
    fgets(newCustomer.address,49, stdin);
    newCustomer.address[strlen(newCustomer.address) - 1] = '\0';

    printf(" Customer State  : ");
    fgets(newCustomer.state, 29, stdin);
    newCustomer.state[strlen(newCustomer.state) - 1] = '\0';

    printf(" Customer Pin : ");
    scanf("%ld", &newCustomer.pin);
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf(" Customer Phone No  : ");
    fgets(newCustomer.phone, 14, stdin);
    newCustomer.phone[strlen(newCustomer.phone) - 1] = '\0';

    printf(" Adding Customer... \n");
    writeCustomertoFile(newCustomer);
    create_report_customer(newCustomer);

    return 0;
}

int writeCustomertoFile(struct customer rec) {
    FILE *wp, *rp;
    struct customer readrec;
    int stat;

    rp = fopen("customer_master.dat", "rb");

    stat = fread(&readrec, sizeof(rec), 1, rp);
    while (stat == 1) {
        if (strncmp(readrec.code, rec.code, sizeof(readrec.code)) == 0) {
            printf(" The Customer code exists in the database \n");
            return -1;
        }
        stat = fread(&readrec, sizeof(rec), 1, rp);
    }
    fclose(rp);

    wp = fopen("customer_master.dat", "ab");
    fwrite(&rec, sizeof(rec), 1, wp);
    printf(" Added Customer... \n");
    fclose(wp);

    return 0;
}

int create_report_customer(struct customer rec) {
    FILE *rp;
    struct customer prec;
    int stat;
    int itemcounter;
    FILE *file = fopen("customer.txt", "w");

    rp = fopen("customer_master.dat", "rb");

    if (file == NULL || rp == NULL) {
        printf("Error opening files.\n");
        return -1;
    }

    fprintf(file, "\n %-15s %-30s %-100s %-20s %-15s \n",
            "Customer Code", "Customer Name", "Customer Address", "Customer State", "Customer Phone No");

    itemcounter = 0;
    stat = fread(&prec, sizeof(rec), 1, rp);
    while (stat == 1) {
        fprintf(file, " %-15s %-30s %-100s %-20s %-15s \n",
                prec.code, prec.name, prec.address, prec.state, prec.phone);
        itemcounter += 1;
        stat = fread(&prec, sizeof(rec), 1, rp);
    }

    printf("\n\n Report Created with %d Records \n", itemcounter);

    fclose(rp);
    fclose(file);
}

int recordPurchaseTransaction() {
    struct transaction newTransaction;
    char ch;

    printf("\n\n\n  PURCHASE TRANSACTION \n\n\n");
    scanf("%c", &ch);

    newTransaction.itemcode[strlen(newTransaction.itemcode) - 1] = '\0';

    printf(" Enter Item Name: ");
    fgets(newTransaction.itemdesc, 50, stdin);
    for (int i = 0; i < strlen(newTransaction.itemdesc); i++) {
        newTransaction.itemdesc[i] = toupper((unsigned char)newTransaction.itemdesc[i]);
    }
    newTransaction.itemdesc[strlen(newTransaction.itemdesc) - 1] = '\0';

    printf(" Quantity: ");
    scanf("%ld", &newTransaction.qty);
    printf(" Total Price: ");
    scanf("%lf", &newTransaction.totalPrice);

    newTransaction.transType = 'P'; // 'P' for Purchase

    char saveChoice;
    printf("\n\n  Do you wish to save this Purchase Transaction (Y/N) : ");
    scanf(" %c", &saveChoice);

    updateInventory(newTransaction.itemdesc, newTransaction.qty, newTransaction.transType);

    writePurchaseTransactionToFile(newTransaction);
    create_report_PurchaseTransaction(newTransaction);

    return 0;
}

int recordSaleTransaction() {
    struct transaction newTransaction;
    char ch;

    printf("\n\n\n  SALE TRANSACTION \n\n\n");
    scanf("%c", &ch);

    printf(" Enter Item Name: ");
    fgets(newTransaction.itemdesc, 50, stdin);
    for (int i = 0; i < strlen(newTransaction.itemdesc); i++) {
        newTransaction.itemdesc[i] = toupper((unsigned char)newTransaction.itemdesc[i]);
    }
    newTransaction.itemdesc[strlen(newTransaction.itemdesc) - 1] = '\0';

    printf(" Quantity: ");
    scanf("%ld", &newTransaction.qty);
    printf(" Total Price: ");
    scanf("%lf", &newTransaction.totalPrice);

    newTransaction.transType = 'S'; // 'S' for Sale

    updateInventory(newTransaction.itemdesc, newTransaction.qty, newTransaction.transType);

    writeSaleTransactionToFile(newTransaction);
    create_report_SaleTransaction(newTransaction);
    
    return 0;
}


int writePurchaseTransactionToFile(struct transaction rec) {
    FILE *wp;
    wp = fopen("Purchasetransaction_log.dat", "ab");

    if (wp == NULL) {
        printf("Error opening transaction log file.\n");
        return -1;
    }

    fwrite(&rec, sizeof(rec), 1, wp);
    printf(" Purchase Transaction recorded.\n");

    fclose(wp);
    return 0;
}

int create_report_PurchaseTransaction(struct transaction rec) {
    FILE *rp;
    struct transaction prec;
    int stat;
    int itemcounter;
    FILE *file = fopen("PurchaseTransaction.txt", "w");

    rp = fopen("Purchasetransaction_log.dat", "rb");

    if (file == NULL || rp == NULL) {
        printf("Error opening files.\n");
        return -1;
    }

    fprintf(file, "\nTransaction itemCode  Transaction itemName    Transaction qty    Transaction total price  \n");

    itemcounter = 0;
    stat = fread(&prec, sizeof(prec), 1, rp);
    while (stat == 1) {
        fprintf(file, "%-20s %-50s %-15ld %-20.2f \n", prec.itemcode, prec.itemdesc, prec.qty, prec.totalPrice);
        itemcounter += 1;
        stat = fread(&prec, sizeof(prec), 1, rp);
    }

    printf("\n\n Report Created with %d Records \n", itemcounter);

    fclose(rp);
    fclose(file);

    return 0;
}


int writeSaleTransactionToFile(struct transaction rec) {
    FILE *wp;
    wp = fopen("Saletransaction_log.dat", "ab");

    if (wp == NULL) {
        printf("Error opening transaction log file.\n");
        return -1;
    }

    fwrite(&rec, sizeof(rec), 1, wp);
    printf(" Sale Transaction recorded.\n");

    fclose(wp);
    return 0;
}

int create_report_SaleTransaction(struct transaction rec) {
    FILE *rp;
    struct transaction prec;
    int stat;
    int itemcounter;
    char ch;
    FILE *file = fopen("SaleTransaction.txt", "w");

    rp = fopen("Saletransaction_log.dat", "rb");

    fprintf(file, "\nTransaction itemCode  Transaction itemName    Transaction qty    Transaction total price  \n");

    itemcounter = 0;
    stat = fread(&prec, sizeof(prec), 1, rp);
    while (stat == 1) {
        fprintf(file, "\n%10s %50s  %7ld  %5.2f \n", prec.itemcode, prec.itemdesc, prec.qty, prec.totalPrice);
        itemcounter += 1;
        stat = fread(&prec, sizeof(prec), 1, rp);
    }
    printf("\n\n Report Created with %d Records \n", itemcounter);
    ch = getchar();
    fclose(rp);
    fclose(file);
}


void customizeitem() {
    FILE *fp;
    struct item updaterec;
    char itemName[31];
    char itemCode[11];
    int found = 0;
    int customizeOption;

    printf("Enter the Item Name to customize: ");
    scanf("%s", itemName);

    printf("Enter the Item Code to customize: ");
    scanf("%s", itemCode);

    fp = fopen("item_master.dat", "r+b");

    if (fp == NULL) {
        printf("Error opening item_master.dat file.\n");
        return;
    }

    // Searching for the item by name and code 
    while (fread(&updaterec, sizeof(updaterec), 1, fp) == 1) {
        if (strcasecmp(updaterec.desc, itemName) == 0 && strcmp(updaterec.code, itemCode) == 0) {
            found = 1;

            // Asking for customization option
            printf("Select customization option:\n");
            printf("1. Customize Price\n");
            printf("2. Customize Reorder Quantity\n");
            printf("3. Customize Both Price and Reorder Quantity\n");
            printf("4. Customize Name of the item\n");
            printf("Option: ");
            scanf("%d", &customizeOption);

            // Updating price, reorder quantity, or both based on the chosen option
            switch (customizeOption) {
                case 1:
                    printf("Enter the new price: ");
                    scanf("%lf", &updaterec.price);
                    break;

                case 2:
                    printf("Enter the new reorder quantity: ");
                    scanf("%ld", &updaterec.reordqty);
                    break;

                case 3:
                    printf("Enter the new price: ");
                    scanf("%lf", &updaterec.price);
                    printf("Enter the new reorder quantity: ");
                    scanf("%ld", &updaterec.reordqty);
                    break;
                
                case 4:
                    printf("Enter new name :");
                    scanf("%s",&updaterec.desc);
                    break;

                default:
                    printf("Invalid option.\n");
                    break;
            }

            // Moving the file cursor to the beginning of the record
            fseek(fp, -sizeof(updaterec), SEEK_CUR);

            // Writing the updated record back to the file
            fwrite(&updaterec, sizeof(updaterec), 1, fp);

            printf("Item customization successful.\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }

    fclose(fp);
}

int displayInventory() {
    FILE *rp;
    struct item readrec;

    printf("\n\n\n  INVENTORY DISPLAY \n\n\n");

    rp = fopen("item_master.dat", "rb");

    if (rp == NULL) {
        printf("Error opening item_master.dat file.\n");
        return -1 ;
    }

    printf("%-10s  %-30s  %-5s  %-7s  %-5s\n", "Item Code", "Description", "Qty", "Price", "Reorder Qty");
    while (fread(&readrec, sizeof(readrec), 1, rp) == 1) {
        printf("%-10s  %-30s  %-5ld  %-7.2f  %-5ld\n", readrec.code, readrec.desc, readrec.qty, readrec.price, readrec.reordqty);
    }

    fclose(rp);
    return 0;
}

void customizeCustomerDetails() {
    char customercodeToCustomize[11];
    printf("Enter the customer code to customize details: ");
    scanf("%s", customercodeToCustomize);

    char choice;
    printf("Do you want to change all details (A) or a particular one (P)? ");
    scanf(" %c", &choice);

    FILE *fp;
    struct customer currentCustomer;

    // Open the customer file in read-write mode
    fp = fopen("customer_master.dat", "rb+");
    if (fp == NULL) {
        printf("Error opening customer_master.dat file.\n");
        return;
    }

    // Search for the customer with the given code
    while (fread(&currentCustomer, sizeof(struct customer), 1, fp) == 1) {
        if (strncmp(currentCustomer.code, customercodeToCustomize, sizeof(currentCustomer.code)) == 0) {

            if (choice == 'A' || choice == 'a') {
                // Customize all details
                printf("Enter the new details for the customer:\n");

                // Customize customer name
                printf("Enter the new name: ");
                scanf("%s", currentCustomer.name);

                // Customize customer address
                printf("Enter the new Address: ");
                scanf("%s", currentCustomer.address);

                // Customize customer phone
                printf("Enter the new phone: ");
                scanf("%s", currentCustomer.phone);

                // Customize customer code
                printf("Enter the new code: ");
                scanf("%s", currentCustomer.code);

                // Customize customer pin
                printf("Enter the new pin: ");
                scanf("%s", currentCustomer.pin);

                // Customize customer state
                printf("Enter the new state: ");
                scanf("%s", currentCustomer.state);

                printf("Customer details updated successfully.\n");
            } else if (choice == 'P' || choice == 'p') {
                // Customize a particular detail
                printf("Choose which detail to change:\n");
                printf("1. Name\n");
                printf("2. Address\n");
                printf("3. Phone\n");
                printf("4. Code\n");
                printf("5. Pin\n");
                printf("6. State\n");

                int option;
                printf("Enter your choice: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("Enter the new name: ");
                        scanf("%s", currentCustomer.name);
                        break;
                    case 2:
                        printf("Enter the new Address: ");
                        scanf("%s", currentCustomer.address);
                        break;
                    case 3:
                        printf("Enter the new phone: ");
                        scanf("%s", currentCustomer.phone);
                        break;
                    case 4:
                        printf("Enter the new code: ");
                        scanf("%s", currentCustomer.code);
                        break;
                    case 5:
                        printf("Enter the new pin: ");
                        scanf("%s", currentCustomer.pin);
                        break;
                    case 6:
                        printf("Enter the new state: ");
                        scanf("%s", currentCustomer.state);
                        break;
                    default:
                        printf("Invalid option. No details changed.\n");
                        fclose(fp);
                        return;
                }

                printf("Customer details updated successfully.\n");
            } else {
                printf("Invalid choice. No details changed.\n");
            }

            // Move the file pointer back to update the existing customer details
            fseek(fp, -sizeof(struct customer), SEEK_CUR);
            fwrite(&currentCustomer, sizeof(struct customer), 1, fp);
            fclose(fp);
            return;
        }
    }

    printf("Customer not found with code %s.\n", customercodeToCustomize);
    fclose(fp);
}


int displayCustomer() {
    FILE *rp;
    struct customer readrec;
    int stat;

    printf("\n\n\n  CUSTOMER DISPLAY \n\n\n");

    rp = fopen("customer_master.dat", "rb");

    if (rp == NULL) {
        printf("Error opening customer_master.dat file.\n");
        return -1;
    }

    printf("%-10s  %-25s  %-35s  %-20s  %-15s\n",
           "Code", "Name", "Address", "State", "Phone");

    stat = fread(&readrec, sizeof(readrec), 1, rp);
    while (stat == 1) {
       printf("%-10s  %-25s  %-40s  %-20s  %-15s\n",
       readrec.code, readrec.name, readrec.address, readrec.state, readrec.phone);

        stat = fread(&readrec, sizeof(readrec), 1, rp);
    }

    fclose(rp);

    return 0;
}


void customizeSupplierDetails() {
    char supplierCodeToCustomize[11];
    printf("Enter the supplier code to customize details: ");
    scanf("%s", supplierCodeToCustomize);

    char choice;
    printf("Do you want to change all details (A) or a particular one (P)? ");
    scanf(" %c", &choice);

    FILE *fp;
    struct supplier currentSupplier;

    fp = fopen("supplier_master.dat", "rb+");
    if (fp == NULL) {
        printf("Error opening supplier_master.dat file.\n");
        return;
    }

    while (fread(&currentSupplier, sizeof(struct supplier), 1, fp) == 1) {
        if (strncmp(currentSupplier.code, supplierCodeToCustomize, sizeof(currentSupplier.code)) == 0) {

            if (choice == 'A' || choice == 'a') {
                // Customize all details
                printf("Enter the new details for the supplier:\n");

                printf("Enter the new name: ");
                scanf("%s", currentSupplier.name);

                printf("Enter the new Address: ");
                scanf("%s", currentSupplier.address);

                printf("Enter the new phone: ");
                scanf("%s", currentSupplier.phone);

                printf("Enter the new code: ");
                scanf("%s", currentSupplier.code);

                printf("Enter the new pin: ");
                scanf("%s", currentSupplier.pin);

                printf("Enter the new state: ");
                scanf("%s", currentSupplier.state);

                printf("Supplier details updated successfully.\n");
            } 
            else if (choice == 'P' || choice == 'p') {
                // Customize a particular detail
                printf("Choose which detail to change:\n");
                printf("1. Name\n");
                printf("2. Address\n");
                printf("3. Phone\n");
                printf("4. Code\n");
                printf("5. Pin\n");
                printf("6. State\n");

                int option;
                printf("Enter your choice: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        printf("Enter the new name: ");
                        scanf("%s", currentSupplier.name);
                        break;

                    case 2:
                        printf("Enter the new Address: ");
                        scanf("%s", currentSupplier.address);
                        break;

                    case 3:
                        printf("Enter the new phone: ");
                        scanf("%s", currentSupplier.phone);
                        break;

                    case 4:
                        printf("Enter the new code: ");
                        scanf("%s", currentSupplier.code);
                        break;

                    case 5:
                        printf("Enter the new pin: ");
                        scanf("%s", currentSupplier.pin);
                        break;

                    case 6:
                        printf("Enter the new state: ");
                        scanf("%s", currentSupplier.state);
                        break;

                    default:
                        printf("Invalid option. No details changed.\n");
                        fclose(fp);
                        return;
                }

                printf("Supplier details updated successfully.\n");
            } 
            else {
                printf("Invalid choice. No details changed.\n");
            }

            fseek(fp, -sizeof(struct supplier), SEEK_CUR);
            fwrite(&currentSupplier, sizeof(struct supplier), 1, fp);
            fclose(fp);
            return;
        }
    }

    printf("Supplier not found with code %s.\n", supplierCodeToCustomize);
    fclose(fp);
}

int displaySupplier() {
    FILE *rp;
    struct supplier readrec;

    printf("\n\n\n  SUPPLIER DISPLAY \n\n\n");

    rp = fopen("supplier_master.dat", "rb");

    if (rp == NULL) {
        printf("Error opening supplier_master.dat file.\n");
        return -1;
    }

    printf("%-10s  %-25s  %-35s  %-20s  %-15s\n",
           "Code", "Name", "Address", "State", "Phone");

    while (fread(&readrec, sizeof(struct supplier), 1, rp) == 1) {
        printf("%-10s  %-25s  %-35s  %-20s  %-15s\n",
               readrec.code, readrec.name, readrec.address, readrec.state, readrec.phone);
    }

    fclose(rp);

    return 0;
}


int displayPurchaseTransactions() {
    FILE *rp;
    struct transaction readrec;

    printf("\n\n\n  PURCHASE TRANSACTIONS DISPLAY \n\n\n");

    rp = fopen("Purchasetransaction_log.dat", "rb");

    if (rp == NULL) {
        printf("Error opening Purchasetransaction_log.dat file for reading.\n");
        return -1;
    }

    printf("%-20s %-7s %-10s\n","Item Name", "Qty", "Total Price");

    while (fread(&readrec, sizeof(struct transaction), 1, rp) == 1) {
        if (readrec.transType == 'P') {
            printf("%-20s %-7ld %-10.2f\n",readrec.itemdesc, readrec.qty, readrec.totalPrice);
        }
    }

    fclose(rp);

    return 0;
}

int displaySaleTransactions() {
    FILE *rp;
    struct transaction readrec;

    printf("\n\n\n  SALE TRANSACTIONS DISPLAY \n\n\n");

    rp = fopen("Saletransaction_log.dat", "rb");

    if (rp == NULL) {
        printf("Error opening Saletransaction_log.dat file for reading.\n");
        return -1;
    }

    printf("%-20s %-7s %-10s\n","Item Name", "Qty", "Total Price");

    while (fread(&readrec, sizeof(struct transaction), 1, rp) == 1) {
        if (readrec.transType == 'S') {
            printf(" %-20s %-7ld %-10.2f\n",readrec.itemdesc, readrec.qty, readrec.totalPrice);
        }
    }

    fclose(rp);

    return 0;
}


void askDisplayOption(char option) {
    printf("Do you want to display information? (Y/N): ");
    char displayOption;
    scanf(" %c", &displayOption);

    if (displayOption == 'Y' || displayOption == 'y') {
        // Display information based on the provided option
        switch (option) {
            case '1':
                displayInventory();
                break;

            case '2':
                displaySupplier();
                break;

            case '3':
                displayCustomer();
                break;

            case '4':
                displayPurchaseTransactions();
                break;

            case '5':
                displaySaleTransactions();
                break;

            default:
                printf("error!!!");
                break;
        }
    }
}

int deleteItem() {
    char itemdescToDelete[50];
    printf("\n\n\n  DELETE ITEM \n\n\n");
    printf(" Enter the Item Name to delete: ");
    scanf("%50s", itemdescToDelete);

    FILE *fp, *temp;
    struct item currentItem;

    fp = fopen("item_master.dat", "rb");
    if (fp == NULL) {
        printf("Error opening item_master.dat file.\n");
        return -1;
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error opening temporary file.\n");
        fclose(fp);
        return -1;
    }

    while (fread(&currentItem, sizeof(struct item), 1, fp) == 1) {

        if (strcasecmp(currentItem.desc, itemdescToDelete) != 0) {
            fwrite(&currentItem, sizeof(struct item), 1, temp);
        } else {
            writeDeletedItemToFile(currentItem.desc);
        }
    }

    fclose(fp);
    fclose(temp);

    if (remove("item_master.dat") != 0) {
        printf("Error deleting the original file.\n");
        return -1;
    }

    if (rename("temp.dat", "item_master.dat") != 0) {
        printf("Error renaming the temporary file.\n");
        return -1;
    }

    printf("Item deleted successfully.\n");

    return 0;
}

void writeDeletedItemToFile(const char *deletedItem) {
    FILE *deletedItemsFile = fopen("deleted_items.txt", "a");

    if (deletedItemsFile == NULL) {
        printf("Error opening deleted_items.txt file.\n");
        return;
    }

    fprintf(deletedItemsFile, "Deleted Item:\n %s", deletedItem);
    fclose(deletedItemsFile);
}


int deleteSupplier() {
    char supplierCodeToDelete[10];
    char supplierNameToDelete[50];

    printf("\n\n\n  DELETE SUPPLIER \n\n\n");
    printf(" Enter the Supplier Code to delete: ");
    scanf("%s", supplierCodeToDelete);

    printf("Enter the Supplier Name to delte:");
    scanf("%s",supplierNameToDelete);

    FILE *fp, *temp;
    struct supplier currentSupplier;

    fp = fopen("supplier_master.dat", "rb");
    if (fp == NULL) {
        printf("Error opening supplier_master.dat file.\n");
        return -1;
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error opening temporary file.\n");
        fclose(fp);
        return -1;
    }

    while (fread(&currentSupplier, sizeof(struct supplier), 1, fp) == 1) {
        if (strncmp(currentSupplier.code, supplierCodeToDelete, sizeof(currentSupplier.code)) != 0) {
            fwrite(&currentSupplier, sizeof(struct supplier), 1, temp);
        }
        else {
            
            writeDeletedSupplierToFile(&currentSupplier);
        }
    }

    fclose(fp);
    fclose(temp);

    if (remove("supplier_master.dat") != 0) {
        printf("Error deleting the original file.\n");
        return -1;
    }

    if (rename("temp.dat", "supplier_master.dat") != 0) {
        printf("Error renaming the temporary file.\n");
        return -1;
    }

    printf("Supplier deleted successfully.\n");

    return 0;
}

void writeDeletedSupplierToFile(const struct supplier *deletedSupplier) {
    FILE *deletedSuppliersFile = fopen("deleted_suppliers.txt", "a");

    if (deletedSuppliersFile == NULL) {
        printf("Error opening deleted_suppliers.txt file.\n");
        return;
    }

    fprintf(deletedSuppliersFile, "Deleted Supplier:\n");
    fprintf(deletedSuppliersFile, "Name: %s\n", deletedSupplier->name);
    fprintf(deletedSuppliersFile, "\n");

    fclose(deletedSuppliersFile);
}

int deleteCustomer() {
    char customerCodeToDelete[11];
    char customerNameToDelete[50];

    printf("\n\n\n  DELETE CUSTOMER \n\n\n");
    printf(" Enter the Customer Code to delete: ");
    scanf("%s", customerCodeToDelete);

    printf(" Enter the Customer Name to delete: ");
    scanf("%s", customerNameToDelete);

    FILE *fp, *temp;
    struct customer currentCustomer;

    // Open the file in read mode
    fp = fopen("customer_master.dat", "rb");
    if (fp == NULL) {
        printf("Error opening customer_master.dat file.\n");
        return -1;
    }

    // Open a temporary file for writing
    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error opening temporary file.\n");
        fclose(fp);
        return -1;
    }

    // Read customers from the original file and write to the temporary file, excluding the customer to delete
    while (fread(&currentCustomer, sizeof(struct customer), 1, fp) == 1) {
        // Check both conditions for deletion
        if (strncmp(currentCustomer.code, customerCodeToDelete, sizeof(currentCustomer.code)) != 0 ||
            strncmp(currentCustomer.name, customerNameToDelete, sizeof(currentCustomer.name)) != 0) {
            fwrite(&currentCustomer, sizeof(struct customer), 1, temp);
        } else {
            // Call the function to write the deleted customer to the text file
            writeDeletedCustomerToFile(&currentCustomer);
        }
    }

    fclose(fp);
    fclose(temp);

    // Remove the original file
    if (remove("customer_master.dat") != 0) {
        printf("Error deleting the original file.\n");
        return -1;
    }

    // Rename the temporary file to the original file
    if (rename("temp.dat", "customer_master.dat") != 0) {
        printf("Error renaming the temporary file.\n");
        return -1;
    }

    printf("Customer deleted successfully.\n");

    return 0;
}

void writeDeletedCustomerToFile(const struct customer *deletedCustomer) {
    FILE *deletedCustomersFile = fopen("deleted_customers.txt", "a");

    if (deletedCustomersFile == NULL) {
        printf("Error opening deleted_customers.txt file.\n");
        return;
    }

    fprintf(deletedCustomersFile, "Deleted Customer:\n");
    fprintf(deletedCustomersFile, "Name: %s\n", deletedCustomer->name);
    fprintf(deletedCustomersFile, "\n");

    fclose(deletedCustomersFile);
}

int deletePurchaseTransaction() {
    char itemNameToDelete[50];

    printf("\n\n\n  DELETE PURCHASE TRANSACTION \n\n\n");
    printf(" Enter the Item Name of the Purchase Transaction to delete: ");
    scanf("%s", itemNameToDelete);

    FILE *fp, *temp;
    struct transaction currentTransaction;

    fp = fopen("Purchasetransaction_log.dat", "rb");
    if (fp == NULL) {
        printf("Error opening Purchasetransaction_log.dat file.\n");
        return -1;
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error opening temporary file.\n");
        fclose(fp);
        return -1;
    }
    while (fread(&currentTransaction, sizeof(struct transaction), 1, fp) == 1) {
        if (strcasecmp(currentTransaction.itemdesc, itemNameToDelete) != 0 || currentTransaction.transType != 'P') {
            fwrite(&currentTransaction, sizeof(struct transaction), 1, temp);
        }
    }


    fclose(fp);
    fclose(temp);

    if (remove("Purchasetransaction_log.dat") != 0) {
        printf("Error deleting the original file.\n");
        return -1;
    }

    if (rename("temp.dat", "Purchasetransaction_log.dat") != 0) {
        printf("Error renaming the temporary file.\n");
        return -1;
    }

    printf("Purchase transaction deleted successfully.\n");

    displayPurchaseTransactions();

    return 0;    
}

int deleteSaleTransaction() {
    char itemNameToDelete[50];

    printf("\n\n\n  DELETE SALE TRANSACTION \n\n\n");
    printf(" Enter the Item Name of the Sale Transaction to delete: ");
    scanf("%s", itemNameToDelete);

    FILE *fp, *temp;
    struct transaction currentTransaction;

    fp = fopen("Saletransaction_log.dat", "rb");
    if (fp == NULL) {
        printf("Error opening Saletransaction_log.dat file.\n");
        return -1;
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error opening temporary file.\n");
        fclose(fp);
        return -1;
    }

   while (fread(&currentTransaction, sizeof(struct transaction), 1, fp) == 1) {
        if (strcasecmp(currentTransaction.itemdesc, itemNameToDelete) != 0 || currentTransaction.transType != 'S') {
            fwrite(&currentTransaction, sizeof(struct transaction), 1, temp);
        }
    }


    fclose(fp);
    fclose(temp);

    // Removing the original file
    if (remove("Saletransaction_log.dat") != 0) {
        printf("Error deleting the original file.\n");
        return -1;
    }

    // Renaming the temporary file to the original file
    if (rename("temp.dat", "Saletransaction_log.dat") != 0) {
        printf("Error renaming the temporary file.\n");
        return -1;
    }

    printf("Sale transaction deleted successfully.\n");

    displaySaleTransactions();

    return 0;
}

void updateInventory(const char *itemCode, long qty, char transType) {
    FILE *file;
    struct item currentItem;

    // Opening the file in read and write mode
    file = fopen("item_master.dat", "rb+");
    if (file == NULL) {
        printf("Error opening item_master.dat file for updating inventory.\n");
        return;
    }

    // Find the item with the specified itemCode
    while (fread(&currentItem, sizeof(struct item), 1, file) == 1) {
        if (strcmp(currentItem.desc, itemCode) == 0) {
            // Updating the inventory based on transaction type
            if (transType == 'P') {
                currentItem.qty += qty; // Increasing quantity for purchase
            } else if (transType == 'S') {
                currentItem.qty -= qty; // Decreasing quantity for sale
            }

            // Move the file pointer to the beginning of the item's record
            fseek(file, -sizeof(struct item), SEEK_CUR);

            // Write the updated item back to the file
            if (fwrite(&currentItem, sizeof(struct item), 1, file) != 1) {
                printf("Error updating item inventory.\n");
            }

            break; // Item found and updated, exit the loop
        }
    }

    fclose(file);
}

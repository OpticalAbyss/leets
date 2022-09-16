#include <vector>
#include <string>
#include <iostream>

using namespace std;


//Two Sums
//vector<int> twoSum(vector<int>& nums, int target) {
//    for (int i = 0; i < nums.size(); i++)
//    {
//        for (int j = i + 1; j < nums.size(); j++)
//        {
//            if ((nums.at(i) + nums.at(j)) == target)
//            {
//                vector<int> a = { i , j };
//                return a;
//            }
//        }
//    }
//    return nums;
//
//}
//};







// Valid Parenthesis
//bool isvalid(std::string s) {
//    std::vector<char> input;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (input.empty())
//        {
//            input.push_back(s.at(i));
//        }
//        else if (
//            (input.back() == '(' && s.at(i) == ')')
//            || (input.back() == '[' && s.at(i) == ']')
//            || (input.back() == '{' && s.at(i) == '}'))
//        {
//            input.pop_back();
//
//        }
//        else
//        {
//            input.push_back(s.at(i));
//        }
//    }
//    if (input.empty())
//    {
//        return true;
//    }
//    else
//        return false;
//
//}



// Palindrome Number
//bool isPalindrome(int x) {
//    //string method
//    string input = to_string(x);
//    for (int i = 0; i < input.size(); ++i)
//    {
//        if (input.at(i) != input.at(input.size() - (i + 1)))
//        {
//            return false;
//        }
//    }
//    return true;
//
//}




// Add Two Numbers
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int powIncrementl1 = 0, l1_sum = 0, l2_sum = 0;
    while (l1->next != nullptr)
    {
        l1_sum += l1->val * pow(10, powIncrementl1);
        l1 = l1->next;
        powIncrementl1++;
    }
    l1_sum += l1->val * pow(10, powIncrementl1);
    powIncrementl1++;

    int powIncrementl2 = 0;
    while (l2->next != nullptr)
    {
        l2_sum += l2->val * pow(10, powIncrementl2);
        l2 = l2->next;
        powIncrementl2++;
    }
    l2_sum += l2->val * pow(10, powIncrementl2);
    powIncrementl2++;

    int newSum = l2_sum + l1_sum;
    int newIncrement = 0;
    if (powIncrementl2 > powIncrementl2)
        newIncrement = powIncrementl2;
    else
        newIncrement = powIncrementl1;

    
    ListNode* A1 = new ListNode(newSum / pow(10, newIncrement), nullptr);
    newIncrement--;
    ListNode* temp = A1;
    for (int i = 0; i < newIncrement; ++i)
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new ListNode(newSum % 10, nullptr);
        //newSum %= 10;
        newIncrement--;
    }
    return temp;
}

void PrintList(ListNode *head) {
    ListNode* temp = head;
    if (temp != NULL) {
        cout << "The list contains: ";
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    else {
        cout << "The list is empty.\n";
    }
}


void push_back(ListNode* head, int newElement) {
    ListNode* newNode = new ListNode();
    newNode->val = newElement;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        ListNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main()
{
    ListNode* Input1 = new ListNode(2, nullptr), *Input2 = new ListNode(5, nullptr);
    push_back(Input1, 4);
    push_back(Input1, 3);

    push_back(Input2, 6);
    push_back(Input2, 4);

    PrintList(addTwoNumbers(Input1, Input2));

    return 0;
}
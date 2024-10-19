/*
Given a string s, return the longest
palindromic
substring
in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
*/
#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        int e = s.length()-i-1;
        if(i == e) return true;
        if(s[i] != s[e]) return false;
    }
    return true;
}

string longestPalindrome(string s) 
{ 
    string longest = " ";
    for(int i = 0; i < s.length(); i++){
        string current;
        for(int k=i; k < s.length(); k++)
        {
            current+=s[k];
            if(is_palindrome(current))
            {
                if(current.length() >= longest.length()){
                    longest = current;
                }
            }
        }
        if(longest.length() >= s.length()-i) break;
    }
    return longest;
}

int main()
{

    cout << longestPalindrome("a") << endl;
    cout << longestPalindrome("aabbaaXYZDFP") << endl;
    cout << longestPalindrome("abbaXYZaabbaaDFP") << endl;
    cout << longestPalindrome("abbaXYZaabaabbaabaaDFP") << endl;

    string large_test_case = "borcdubqiupahpwjizjjbkncelfazeqynfbrnzuvbhjnyvrlkdyfyjjxnprfocrmisugizsgvhszooktdwhehojbrdbtgkiwkhpfjfcstwcajiuediebdhukqnroxbgtvottummbypokdljjvnthcbesoyigscekrqswdpalnjnhcnqrarxuufzzmkwizptyvjhpfidgmskuaggtpxqisdlyloznkarxofzeeyvteynluofuhbllyiszszbwnsglqjkignusarxsjvctpgiwnhdufmfpanfwxjwlmhgllzsmdpncbwnsbdtsvrjybynifywkulqnzprcxockbhrhvnwxrkvwumyieazclcviumvormynbryaziijpdinwatwqppamfiqfiojgwkvfzyxadyfjrgmtttvlgkqghgbcfhkigfojjkhskzenlpasyozcsuccdxhulcubsgomvcrbqwakrraesfifecmoztayrdjicypakrrneulfbqqxtrdelggedvloebqaztmfyfkhuonrognejxpesmwgnmnnnamvkxqvzrgzdqtvuhccryeowywmbixktnkqnwzlzfvloyqcageugmjqihyjxhssmhkfzxpzxmgpjgsduogfolnkkqizitbvvgrkczmojxnabruwwzxxqcevdwvtiigwckpxnnxxxdhxpgomncttjutrsvyrqcfwxhexhaguddkiesmfrqfjfdaqbkeqinwicphktffuwcazlmerdhraufbpcznbuipmymipxbsdhuesmcwnkdvilqbnkaglloswcpqzdggnhjdkkumfuzihilrpcvemwllicoqiugobhrwdxtoefynqmccamhdtxujfudbglmiwqklriolqfkknbmindxtljulnxhipsieyohnczddabrxzjmompbtnnxvivmoyfzfrxlufowtqzojfclmatthjtbhotdoheusnpirwicbtyrcuojsdmfcx";
    cout << longestPalindrome(large_test_case);
    return 0;
}
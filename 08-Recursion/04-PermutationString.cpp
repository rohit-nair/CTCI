#include <iostream>
#include <vector>

static int COUNTER = 0;

// Top down.
void PermutationTopDown(std::string s, std::string perm, int iteration) {
    if (s.length() == iteration) {
        std::cout << perm << "\n";
        ++COUNTER;
        return;
    }
    
    std::string pastPerm = perm;
    for (int i = 0; i <= iteration; i++) {
        perm.insert(i, 1, s[iteration]);
        PermutationTopDown(s, perm, iteration+1);
        perm = pastPerm;
    }
}

// Bottom up
std::vector<std::string> PermutationBottomUp(std::string s) {
    if (s.length() == 1) {
        std::vector<std::string> perms;
        perms.push_back(s);
        return perms;
    }
    
    char firstChar = s[0];
    char* currentPos = &s[1];
    std::vector<std::string> perms = PermutationBottomUp(currentPos);
    std::vector<std::string> modPerms;
    
    for (int i = 0; i < perms.size(); i++) {
        std::string perm = perms[i];
        for (int j = 0; j <= perm.length(); j++) {
            std::string tempPerm = perm;
            modPerms.push_back(tempPerm.insert(j, 1, firstChar));
        }
    }
    
    return modPerms;
}

int main() {
    std::string text = "abcd";
    PermutationTopDown(text, "", 0);
    std::cout << "Permuations: " << COUNTER << "\n";
    
    std::cout << "\n\n";
    std::vector<std::string> perms = PermutationBottomUp(text);
    std::vector<std::string>::iterator it = perms.begin();
    while (it != perms.end()) {
        std::cout << *it++ << "\n";
    }
    
    std::cout << "Permutations: " << perms.size() << "\n";
    
    return 0;
}

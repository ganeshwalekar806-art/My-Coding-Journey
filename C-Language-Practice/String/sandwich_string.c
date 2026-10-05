#include <stdio.h>
#include <string.h>

// अक्षर वॉव्हेल (a, e, i, o, u) आहे की नाही हे तपासणारे फंक्शन
int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int n;
    scanf("%d", &n); // स्ट्रिंगची लांबी घेणे[cite: 1]
    
    char s[30];
    scanf("%s", s); // स्ट्रिंग इनपुट घेणे[cite: 1]
    
    int sandwich_count = 0; // सँडविच सबस्ट्रिंग्सची मोजणी[cite: 1]
    
    // सबस्ट्रिंगची सुरुवात (i) आणि शेवट (j) निश्चित करण्यासाठी लूप
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            
            // १. पहिली अट: टोकाची अक्षरे समान असावीत[cite: 1]
            if (s[i] != s[j]) {
                continue;
            }
            
            int length = j - i + 1; // सबस्ट्रिंगची लांबी
            int isValid = 1; // सबस्ट्रिंग व्हॅलिड आहे की नाही हे ठरवण्यासाठी
            
            // २. मध्यभागी असणारी अक्षरे आणि इतर कॉन्सोनंट्स तपासणे[cite: 1]
            if (length % 2 != 0) { // विषम लांबी (Odd length)[cite: 1]
                int mid = (i + j) / 2;
                
                // मध्यभागी वॉव्हेल नसेल तर अमान्य[cite: 1]
                if (!isVowel(s[mid])) {
                    isValid = 0;
                } else {
                    // टोकाची अक्षरे आणि मधील वॉव्हेल सोडून बाकी सर्व कॉन्सोनंट्स असावेत[cite: 1]
                    for (int k = i + 1; k < j; k++) {
                        if (k != mid && isVowel(s[k])) {
                            isValid = 0;
                            break;
                        }
                    }
                }
            } else { // सम लांबी (Even length)[cite: 1]
                int mid1 = (i + j) / 2;
                int mid2 = mid1 + 1;
                
                // मध्यभागी असणारी दोन्ही अक्षरे वॉव्हेल नसतील तर अमान्य[cite: 1]
                if (!isVowel(s[mid1]) || !isVowel(s[mid2])) {
                    isValid = 0;
                } else {
                    // टोकाची अक्षरे आणि मधील दोन्ही वॉव्हेल्स सोडून बाकी सर्व कॉन्सोनंट्स असावेत[cite: 1]
                    for (int k = i + 1; k < j; k++) {
                        if (k != mid1 && k != mid2 && isVowel(s[k])) {
                            isValid = 0;
                            break;
                        }
                    }
                }
            }
            
            // जर सर्व अटी पूर्ण झाल्या असतील, तर काउंट वाढवा[cite: 1]
            if (isValid) {
                sandwich_count++;
            }
        }
    }
    
    printf("%d\n", sandwich_count); // उत्तर प्रिंट करा[cite: 1]
    
    return 0;
}
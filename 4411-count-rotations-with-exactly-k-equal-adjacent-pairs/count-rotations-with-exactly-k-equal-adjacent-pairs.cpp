class Solution {
public:
    int countRotations(string s, int k) {
//maine kaha ki pahle equal pair count karo string ka jitne equal pair aajaye wo total pair hai agar ham in total pair ko disturb karenge toh answer total-1 hoga agar in equal pair ko disturb na kare to answer total hoga 0--n-1 length rotation means we can exclude one pair eah time if ecluded pair is equal then answer for that rotation is total-1 other wise answer for that rotation si total ,agar hame k==total ka pucha hai it means aise kitne rotation hong jinme equal pair ka count total ke barabar ho iska mtlab jinme ham equal pair ko exclude na kar rahe ho uska answer n-total inn number of rotations me ham different charcetr pair ko remove kar rahe honge

        int n = s.size();
        int total = 0;

       
        for(int i = 0; i < n; i++) {

            int j = (i + 1) % n;

            if(s[i] == s[j]) {
                total++;
            }
        }
      
       
        if(k == total) {
            return n - total;
        }

        
        if(k == total - 1) {
            return total;
        }

        return 0;
    }
};
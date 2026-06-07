class Solution {
public:
    string intToRoman(int num) {
        string answer = "";
        while (num > 0) {
            if (num / 1000 > 0) {
                for (int i = 0; i < num / 1000; i++) {
                    answer += "M";
                }
            }
            num %= 1000;

            if (num / 500 == 1) {
                if (num / 100 == 9) {
                    answer += "CM";
                    num %= 100;
                } else {
                    answer += "D";
                }
            }  else if (num / 500 == 0) {
                if (num / 100 == 4) {
                    answer += "CD";
                    num %= 100;
                }
            }
            num %= 500;

            for (int i = 0; i < num / 100; i++) {
                answer += "C";
            }

            num %= 100;

            if (num / 50 == 1) {
                if (num / 10 == 9) {
                    answer += "XC";
                    num %= 10;
                } else {
                    answer += "L";
                }
            } else if (num / 50 == 0) {
                if (num / 10 == 4) {
                    answer += "XL";
                    num %= 10;
                }
            }
            num %= 50;

            for (int i = 0; i < num / 10; i++) {
                answer += "X";
            }
            num %= 10;

            if (num / 5 == 1) {
                if (num / 1 == 9) {
                    answer += "IX";
                    num %= 1;
                } else {
                    answer += "V";
                }
            } else if (num / 5 == 0) {
                if (num / 1 == 4) {
                    answer += "IV";
                    num %= 1;
                }
            }
            num %= 5;

            for (int i = 0; i < num / 1; i++) {
                answer += "I";
            }
            num %= 1;
        }

        return answer;
    }
};
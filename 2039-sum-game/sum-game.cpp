class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int left_sum = 0;
        int left_question = 0;

        int right_question = 0;
        int right_sum = 0;

        for(int i = 0; i < n / 2; i++) {

            if(num[i] == '?')
                left_question++;
            else
                left_sum += num[i] - '0';
        }

        for(int i = n / 2; i < n; i++) {

            if(num[i] == '?')
                right_question++;
            else
                right_sum += num[i] - '0';
        }

        int total_question = left_question + right_question;

        if(left_sum > right_sum) {

            if(left_question == right_question)
                return true;

            else if(left_question > right_question)
                return true;

            else {

                int difference = left_sum - right_sum;

                int question_difference =
                    right_question - left_question;

                if(question_difference % 2 == 0 &&
                   difference == 9 * (question_difference / 2))
                    return false;

                return true;
            }
        }

        else if(left_sum == right_sum) {

            if(left_question == right_question)
                return false;

            else
                return true;
        }

        else {

            if(left_question == right_question)
                return true;

            else if(right_question > left_question)
                return true;

            else {

                int difference = right_sum - left_sum;

                int question_difference =
                    left_question - right_question;

                if(question_difference % 2 == 0 &&
                   difference == 9 * (question_difference / 2))
                    return false;

                return true;
            }
        }

        return true;
    }
};
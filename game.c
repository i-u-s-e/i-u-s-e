#include <stdio.h>
int main() {
    int score1 = 0;                       //declaring the VARIABLES
    int score2 = 0;
    int score3 = 0;
    int totalQuestions1 = 5;
    int totalQuestions2 = 5;
    int totalQuestions3 = 5;
    printf("Welcome to the Quiz Game!\n");
    printf("1. History Quiz\n2. Math Quiz\n3. Science Quiz\n4. Exit\n");
        int choice;
        printf("Enter your choice: ");                     // Choice of user to select which quiz he wants
        scanf("%d", &choice);
     if (choice == 1){                   
         
    printf("WELCOME TO THE HISTORY QUIZ\n.Answer the following questions (choose A, B, C, or D):\n");

    // Question 1
    printf("1. Who among the following ruler was defeated by Seleucus?\n");
    printf("   A. Chandra Gupta Maurya\n  B. Vikramaditya\n  C.Chanakya\n  D. None of the above\n");    //wrote questions and options 
    char answer1;
    scanf(" %c", &answer1);                                   //declared the correct option
    if (answer1 == 'A' || answer1 == 'a') {
        printf("Correct!\n");                               
        score1++;            //If correct score will increase by 1
    } else {
        printf("Wrong! \n"); //If wrong no change to the score
    }

    // Question 2
    printf("2. When was Indian National song sung for the first time?\n");
    printf("   A. 1896 session of the Indian National Congress\n   B. 1857 revolt\n   C. 1919 - Jallianwala Bagh Massacre\n   D. 1945\n");
    char answer2;
    scanf(" %c", &answer2);
    if (answer2 == 'A' || answer2 == 'a') {
        printf("Correct!\n");
        score1++;
    } else {
        printf("Wrong! \n");
    }

    // Question 3
    printf("3. Where did the formation of Azad Hind Fauj take Place?\n");
    printf(" A. Thailand\n   B. Russia\n   C. Singapore\n   D. Germany\n");
    char answer3;
    scanf(" %c", &answer3);
    if (answer3 == 'C' || answer3 == 'c') {
        printf("Correct!\n");
        score1++;
    } else {
        printf("Wrong! \n");
    }
    
    // Question 4
    printf("4. The Battle of Plassey was fought in\n");
    printf("   A. 1757\n  B. 1789\n  C.1709\n  D. None of the above\n");
    char answer4;
    scanf(" %c", &answer1);
    if (answer4 == 'A' || answer4 == 'a') {
        printf("Correct!\n");
        score1++;
    } else {
        printf("Wrong! \n");
    }
    
    // Question 5
    printf("5.The title of 'Viceroy' was added to the office of the Governor-General of India for the first time in?\n");
    printf("   A. 1858\n  B. 1857\n  C.1830\n  D. None of the above\n");
    char answer5;
    scanf(" %c", &answer5);
    if (answer5 == 'A' || answer1 == 'a') {
        printf("Correct!\n");
        score1++;
    } else {
        printf("Wrong! \n");
    }
    
    printf("Quiz completed!\n", totalQuestions1);       //Completion of the 5 question
    
    if (score1 == totalQuestions1) {                       //Declaring the result
        printf("Outstanding! You scored 5/5. Great job!\n");          
    } else if (score1 >= 4) {
        printf("Very good! You scored %d/5. Well done!\n", score1);
    } else if (score1 >= 3){
        printf("Good!. Your score is %d/5.\n", score1);
    }else {
        printf("Keep practicing. Your score is %d/5.\n", score1);
}
 }
     else if(choice==2){
        printf("WELCOME TO THE MATH QUIZ\n.Answer the following questions (choose A, B, C, or D):\n");

    // Question 1
    printf("1. 33*33\n");
    printf("   A. 1089\n  B. 1999\n  C.9999\n  D. None of the above\n");
    char answer6;
    scanf(" %c", &answer6);
    if (answer6 == 'A' || answer6 == 'a') {
        printf("Correct!\n");
        score2++;
    } else {
        printf("Wrong! \n");
    }

    // Question 2
    printf("2. 109+111\n");
    printf("   A. 220\n   B. 200\n   C. 210 \n   D. 222\n");
    char answer7;
    scanf(" %c", &answer7);
    if (answer7 == 'A' || answer7 == 'a') {
        printf("Correct!\n");
        score2++;
    } else {
        printf("Wrong! \n");
    }

    // Question 3
    printf("3. 458*223?\n");
    printf("   A. 102222\n   B. 11123\n   C. 102134\n   D. 23445\n");
    char answer8;
    scanf(" %c", &answer8);
    if (answer8 == 'C' || answer8 == 'c') {
        printf("Correct!\n");
        score2++;
    } else {
        printf("Wrong! \n");
    }
    
    // Question 4
    printf("4. 9x+100=1\n Then x=? \n");
    printf("   A. -11\n  B. 11\n  C.10\n  D. None of the above\n");
    char answer9;
    scanf(" %c", &answer9);
    if (answer9 == 'A' || answer9 == 'a') {
        printf("Correct!\n");
        score2++;
    } else {
        printf("Wrong! \n");
    }
    
    // Question 5
    printf("1234*569\n");
    printf("   A. 702146\n  B. 111234\n  C.78928\n  D. 789123\n");
    char answer10;
    scanf(" %c", &answer10);
    if (answer10 == 'A' || answer10 == 'a') {
        printf("Correct!\n");
        score2++;
    } else {
        printf("Wrong! \n");
    }
    
    printf("Quiz completed!\n", totalQuestions2);
    
    if (score2 == totalQuestions2) {
        printf("Outstanding! You scored 5/5. Great job!\n");
    } else if (score2 >= 4) {
        printf("Very good! You scored %d/5. Well done!\n", score2);
    } else if (score2 >= 3){
        printf("Good!. Your score is %d/5.\n", score2);
    }else {
        printf("Keep practicing. Your score is %d/5.\n", score2);
}

}else if(choice==3){  
    printf("WELCOME TO THE SCIENCE QUIZ\n.Answer the following questions (choose A, B, C, or D):\n");

    // Question 1
    printf("1. Which of the following is a non metal that remains liquid at room temperature?\n");
    printf(" A. Bromine\n B. Phosphorous\n C. Chlorine\n D. None of the above\n");
    char answer11;
    scanf(" %c", &answer11);
    if (answer11 == 'A' || answer11 == 'a') {
        printf("Correct!\n");
        score3++;
    } else {
        printf("Wrong! \n");
    }

    // Question 2
    printf("2. Chlorophyll is a naturally occurring chelate compound in which central metal is\n");
    printf("   A. copper\n   B. magnesium\n   C. iron \n   D. calcium\n");
    char answer12;
    scanf(" %c", &answer12);
    if (answer12 == 'B' || answer12 == 'b') {
        printf("Correct!\n");
        score3++;
    } else {
        printf("Wrong! \n");
    }

    // Question 3

    printf("3. Which of the following is used in pencils? \n");
    printf("   A. Phosphorous\n   B. Silicon\n   C. Graphite\n   D. coal\n");
    char answer13;
    scanf(" %c", &answer13);
    if (answer13 == 'C' || answer13 == 'c') {
        printf("Correct!\n");
        score3++;
    } else {
        printf("Wrong! \n");
    }
    
    // Question 4
    printf("4. Which of the following metals forms an amalgam with other metals? \n");
    printf("   A. Mercury\n  B. Lead\n  C. Tin\n  D. Zinc\n");
    char answer14;
    scanf(" %c", &answer14);
    if (answer14 == 'A' || answer14 == 'a') {
        printf("Correct!\n");
        score3++;
    } else {
        printf("Wrong! \n");
    }
    
    // Question 5
    printf("Chemical formula for water is\n");
    printf("   A. H20\n  B. HCl\n  C.NaOH\n  D. HO\n");
    char answer15;
    scanf(" %c", &answer15);
    if (answer15 == 'A' || answer15 == 'a') {
        printf("Correct!\n");
        score3++;
    } else {
        printf("Wrong! \n");
    }
    
    printf("Quiz completed!\n", totalQuestions3);
    
    if (score3 == totalQuestions3) {
        printf("Outstanding! You scored 5/5. Great job!\n");
    } else if (score3 >= 4) {
        printf("Very good! You scored %d/5. Well done!\n", score3);
    } else if (score3 >= 3){
        printf("Can do better!. Your score is %d/5.\n", score3);
    }else {
        printf("Keep practicing. Your score is %d/5.\n", score3);
}
    
}
else if(choice==4){
      printf("Goodbye!!!!\nEXIT");                       //If user wants to exit the program
exit(0); 
    
}
else{
      printf("Invalid choice");                          //if seleceted Other than the above options of test
}

    return 0;
}

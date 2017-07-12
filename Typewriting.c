//  project 타자연습
//  Created by 허경영 on 14. 6. 1.
//  Copyright (c) 2014년 SoongSil Univ. All rights reserved.
//

#include <stdio.h>
#include <termios.h> //getch()함수 이용
#include <stdlib.h> // random함수 생성시 사용
#include <time.h>
#include <sys/time.h>
#include <string.h> // 낱말비교시 이용

int menuPrint();
int getch();
void firstFunc(); // 자리 연습 함수 호출
void secondFunc(); // 낱말 연습 함수 호출
void thirdFunc(); // 짧은 글 연습 함수 호출
void fourthFunc(); // 긴 글 연습 함수 호출

int main(void)
{
    while (1)
    {
	//system("clear");
        short choice;
        choice = menuPrint(); // 메뉴함수 호출
    
        switch (choice) {
            case 1:
                //printf(">> 영문 타자 연습 프로그램 : 자리 연습 <<");
                firstFunc();
                break;
            case 2:
                //printf(">> 영문 타자 연습 프로그램 : 낱말 연습 <<");
                secondFunc();
                break;
            case 3:
                //printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<");
                thirdFunc();
                break;
            case 4:
                //printf(">> 영문 타자 연습 프로그램 : 긴 글 연습 <<");
                fourthFunc();
                break;
            case 5:
                printf(">> 프로그램 종료 <<\n");
                return 0;
            default:
                return 0;
        }
    }
    
    return 0;
}

int getch(void)
{
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0, &save);
	buf=save;
    
	buf.c_lflag&=~(ICANON|ECHO);
	buf.c_cc[VMIN]=1;
	buf.c_cc[VTIME]=0;
    
	tcsetattr(0, TCSAFLUSH, &buf);
    
	ch=getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}


int menuPrint(void)
{
    int choice = 0;
    
    printf(">> 영문 타자 연습 프로그램 5<<\n");
    printf("1. 자리 연습\t2.낱말 연습\n");
    printf("3. 짧은 글 연습\t4.긴 글 연습\n");
    printf("5. 프로그램 종료\n");
    printf("\n");
    printf("번호를 선택 하세요 : ");
    scanf("%d", &choice);
    
    return choice;
}

void firstFunc()
{
    int temp;
    int i = 0;
    char big_a = 65; // A의 ASCII코드 시작 값
    char small_a = 97; // a의 ASCII코드 시작 값
    short ran_num; 
    int jari_arr[20] = {0,}; // 랜덤 a~z, A~Z를 저장하는 배열
    int cnt = 0;
    int progress = 0; // 진행률 계산하는 변수
    float wrong = 0; // 오타를 카운트 해주는 변수
    float right = 0; // 정확도 계산하기위한 변수 (맞은 자리수)
    float perfect = 0; // 정확도
    srand(time(NULL));
    
    for(i = 0 ; i < 20 ; i++)
    {
        ran_num = (rand() % 26);
        
        if(ran_num % 2 == 0)
        {
            jari_arr[i] = big_a + ran_num;
        }
        else {
            jari_arr[i] = small_a + ran_num;
        }
    }
    
    getchar();
    
    while(1)
    {
        system("clear");
        printf("\n");
        
        if(wrong == 0)
        {
            perfect = 100;
        }
        else 
        {
            perfect = (1 - (wrong / (right+wrong))) * 100;
        }
        
        if(right == 0)
        {
            perfect = 0;
        }
        printf(">> 영문 타자 연습 프로그램 : 자리 연습 <<\n");
        printf("진행도 : %d%%  오타수 : %d   정확도 : %.lf%%\n", progress, (int)wrong,perfect);
        printf("\n%c\n", jari_arr[cnt]);
        
        temp = getch();
	//printf("%c", temp);
        
        
        if(temp == 27)
        {
            printf("\n>> 메뉴로 복귀 합니다. <<\n");
            return;
        }
        if(jari_arr[cnt] == temp)
        {
            progress += 5;
            right++;
            cnt++;
            if(cnt == 20)
            {
		system("clear");
                printf(">> 영문 타자 연습 프로그램 : 자리 연습 <<\n");
                printf("진행도 : %d%%  오타수 : %d   정확도 : %.lf%%\n", progress, (int)wrong,perfect);
                printf("\n>> Press Enter Key <<");
                if(getch() == '\n')
                {
                    printf(">> 메뉴로 복귀 합니다. <<\n");
                    return;
                }
            }
            continue;
        }
        else 
        {
            wrong++;
            printf("\n");
            printf("틀렸습니다. 다시 입력하세요!\n");
        }
    }
}

void secondFunc()
{
    int ran_num;
    int cnt = 0;
    char temp[20] = {0,};
    int progress = 0; // 진행률 계산하는 변수
    float wrong = 0; // 틀린 단어를 카운트 해주는 변수
    float right = 0; // 정확도 계산하기위한 변수 (맞은 단어수)
    float perfect = 0; // 정확도
    
    
    srand(time(NULL));
    
    char *word_bag[100] = {"add", "salad", "as", "ad", "dad", "Dallas", "fall", "Alaska", "LA", "all", "ask", "from", "close", "make", "sure", "see", "old", "with", "lesson", "point", "elementary", "what", "new", "help", "listen", "grade", "age", "guess", "play", "here", "teacher", "many", "head", "happy", "country", "very", "warm", "like", "soccer", "nature", "name", "read", "meet", "year", "give", "ahead", "movie", "much", "address", "email", "get", "family", "song", "thank", "friend", "number", "class", "now", "pop", "member", "picture", "fat", "grandparent", "long", "painting", "cartoon", "online", "dog", "same", "dark", "different", "fashion", "star", "wavy", "welcome", "think", "curly", "engineer", "gather", "communication", "cute", "best", "diligent", "short", "cousin", "party", "small", "parent", "big", "live", "tall", "black", "twin", "find", "right", "live", "bank", "birthday", "blond", "sport"};
    
    while(cnt < 20)
    {
        printf("\n");
	system("clear");
        ran_num = (rand() % 100);
        
        if(wrong == 0)
        {
            perfect = 100;
        }
        else 
        {
            perfect = (1 - (wrong / (right+wrong))) * 100;
        }
        
        if(right == 0)
        {
            perfect = 0;
        }
        
        printf(">> 영문 타자 연습 프로그램 : 낱말 연습 <<\n");
        printf("진행도 : %d%%  오타수 : %d   정확도 : %.lf%%\n", progress, (int)wrong, perfect);

        printf("\n%s\n", *(word_bag + ran_num));
        scanf("%s", temp);
        
        if(strcmp(temp, "###") == 0)
        {
            printf(">> 메뉴로 복귀 합니다. <<\n");
            return;
        }
        
        if(strcmp(word_bag[ran_num], temp) == 0)
        {
            progress += 5;
            right++;
        }
        else
        {
            progress += 5;
            wrong++;
        }
            
        cnt++;
        if(cnt == 20)
        {
	    system("clear");
	    printf(">> 영문 타자 연습 프로그램 : 낱말 연습 <<\n");
            printf("진행도 : %d%%  오타수 : %d   정확도 : %.lf%%\n", progress, (int)wrong,perfect);
            printf("\n>> Press Enter Key <<");
            getchar();
            if(getchar() == '\n')
            {
                printf(">> 메뉴로 복귀 합니다. <<\n");
                return;
            }
        }
    }
}

void thirdFunc()
{
    char ch;
    int ran_num;
    int cnt = 0;
    char words_temp[50] = {0,};
    char str_temp[50] = {0,};
    int back_check[50] = {0,};
    int check_num;
    int progress = 0; // 진행률 계산하는 변수
    float wrong = 0; // 틀린 단어를 카운트 해주는 변수
    float right = 0; // 정확도 계산하기위한 변수 (맞은 단어수)
    float perfect = 0; // 정확도
    float current = 0; // 현재타수
    float best = 0; // 최고타수
    int i = 0;
    int j = 0;
    float finish_time = 0;
    int temp = 0;
    struct timeval begin, end;

    char *words_bag[30] = {
        "Courage is resistance to fear, mastery of fear - not absence of fear",
        "Poetry is the mother tongue of mankind",
        "Misery loves company",
        "Man is but a reed, the weaken in nature, but he is a thinking reed",
        "Who reflects too much will accomplish little",
        "Man should keep his friendship in constant repair",
        "The right people in the right jobs",
        "Time is the rider that breaks youth",
        "A deep distress hath humanized my soul",
        "Who reflects too much will accomplish little",
        "Nature does not proceed by leaps",
        "Man is a voluntary agent",
        "Men have no right to what is not reasonable",
        "Wealth brings with it many anxieties",
        "Being in a ship is being in a jail, with the chance of being drowned",
        "Life is a progress from want to want, not from enjoyment to enjoyment",
        "Life is half spent before we know what it is",
        "The first virtue of a painting is to be a feast for the eyes",
        "Love truth, but pardon error",
        "It is a wise father that knows his own child",
        "A man apt to promise is apt to forget",
        "We are not hypocrites in our sleep",
        "Genius does what it must, and talent does what it can",
        "The right people in the right jobs",
        "Experience is the only prophecy of wise men",
        "You never miss the water till the well runs dry",
        "A little learning is a dangerous thing",
        "No one can be more wise than destiny",
        "Old men are always young enough to learn, with profit",
        "Music has charms to soothe a savage breast"
    };
    
    srand(time(NULL));
    
    while(cnt < 5)
    {   
	gettimeofday(&begin, NULL);
        system("clear");
	right = 0;
	wrong = 0;
	perfect = 0;
	current = 0;
        
        printf("\n");

        ran_num = (rand() % 30);
        
        for(i = 0 ; i < strlen(words_bag[ran_num]) ; i++)
            words_temp[i] = words_bag[ran_num][i];
          
        
        if(cnt == 0){
	    getchar();
	}
        
	printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
	printf("진행도 : %d%%  현재타수 : %d  최고타수 : %d  정확도 : %.lf%%\n", progress, (int)current, (int)best, perfect);
	printf("%s\n", *(words_bag + ran_num));
	i = 0;
	check_num = 0;
	while((ch = getch()) != '\n')
	{
	    if(ch == 27) //ESC 
	    {
		printf("\n>> 메뉴로 복귀 합니다. <<\n");
		return;
	    }

	    system("clear");

	    str_temp[i] = (char)ch;

	    if(ch == (int)words_temp[i])
	    {
		gettimeofday(&end, NULL);
		finish_time = (float)(end.tv_sec - begin.tv_sec);
		current = ((i+1) / finish_time) * 60;
		temp = current;

		    if(best < temp)
			best = temp;
		

		right++;
		back_check[check_num] = 1;
		check_num++;
	    }
	    else
	    {
		wrong++;
		back_check[check_num] = 2;
		check_num++;
	    }

	    if(wrong == 0)
	    {
		perfect = 100;
	    }
	    else 
	    {
		perfect = (1 - (wrong / (right+wrong))) * 100;
	    }

	    if(right == 0)
	    {
		perfect = 0;
	    }

	    printf("\n>> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
	    printf("진행도 : %d%%  현재타수 : %d  최고타수 : %d  정확도 : %.lf%%\n", progress, (int)current, (int)best, perfect);
	    
	    
	    printf("%s\n", *(words_bag + ran_num));
	    str_temp[i] = (char)ch;


	    if(i > 0) //BackSpace
	    {
		if(ch == 127)
		{   
		    i--;
		    check_num--;

		    for(j = 0 ; j < check_num ; j++)
		    {
			if(check_num == 1)
			    right++;
			if(check_num == 2)
			    wrong++;
		    }
		    perfect = (1 - (wrong / (right+wrong))) * 100;
		    system("clear");
		    printf("\n>> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
		    printf("진행도 : %d%%  현재타수 : %d  최고타수 : %d  정확도 : %.lf%%\n", progress, (int)current, (int)best, perfect);

		    printf("%s\n", *(words_bag + ran_num));
		    for(j = 0 ; j < i ; j++)
			printf("%c",str_temp[j]);

		    continue;
		}
	    }


	    for(j = 0 ; j <= i ; j++)
		printf("%c",str_temp[j]);

	    i++;
	}

	//printf("%s %s\n", words_bag[ran_num], str_temp);
	if(strcmp(words_bag[ran_num], str_temp) == 0)
	{
	    progress += 20;
	    right++;
	    //printf("right\n");
	}
	else
	{
	    progress += 20;
	    wrong++;
	    //printf("wrong\n");
	}
	memset(str_temp, 0, strlen(str_temp));
	cnt++;
	if(cnt == 5)
	{
	    system("clear");
	    perfect = (1 - (wrong / (right+wrong))) * 100;
	    printf("\n>> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
	    printf("진행도 : %d%%  현재타수 : %d  최고타수 : %d  정확도 : %.lf%%\n", progress, (int)current, (int)best, perfect);
	    printf("\n>> Press Enter Key <<\n");
	    if(getchar() == '\n')
	    {
		printf(">> 메뉴로 복귀 합니다. <<\n");
		return;
	    }
	}

    }
}

void fourthFunc()
{
    int i;
    int ran_num;
    char *long_words0[11] = 
    {
		"The Selfish Giant",
		"Every afternoon, as they were coming from school, the children used",
		"to go and play in the Giant's garden.",
		"It was a large lovely garden, with soft green grass. Here and there",
		"over the grass stook beautiful flowers like stars, and there were",
		"twelve peachtrees that in the springtime broke out into delicate blos-",
		"soms of pink and pear I, and in the autumn bore rich fruit. The birds",
		"sat in the trees and sang so sweetly that the children used to stop",
		"their games in order to listen to them. \"How happy we are here!\" they",
		"cried to each other."
    };
    
    char *long_words1[11] = 
    {
		"Rapunzel",
		"There once lived a man and his wife, who had long wished for a child,",
		"but in vain. Now there was at the back of their house a little window",
		"which over looked a beautiful garden full of the finest vegetables and",
		"flowers; but there was a high wall all round it, and no one ventured",
		"into it, for it belonged to a witch of great might, and of whom all",
		"the world was afraid. One day, when the wife was standing at the win-",
		"dow, and looking into the garden, she saw a bed filled with the finest",
		"rampion; and it looked so fresh and green that she began to wish for",
		"some; and at length she longed for it greatly."	
    };
    char *long_words2[11] = 
    {
		"Narcissus",
		"Long, long ago, there lived in Greece a young boy named Narcissus.",
		"All day long he tended his sheep in the hills, and drove them from",
		"place to place to find the very best pasture.",
		"One day he came to a little stream and wanted to drink form it. The",
		"water was very clear and reflected everything that leaned over it.",
		"While Narcissus was waiting for the sheep to drink, he chanced to see",
		"his own face in the water.",
		"He had never seen his likeness before, and he was so pleased with the",
		"pretty picture that he looked at it for a long time." 
    };
    char *long_words3[11] = 
    {
		"Gulliver's Travels",
		"I am Lemuel Gulliver. I was born in England. When I grew up, I had a",
		"great wish to go round the world, and in the year 1699, I got on board",
		"a ship bound for the South Seas. For some time things went all right.",
		"But one day a great storm drove us far to the south and at last the",
		"whip ran on a rock and split her bow. We let down a boat and left the",
		"wreck. But a big wave sank the boat, and I lost sight of my poor",
		"friends.",
		"I swam on and on, and just when I felt I must give myself up, I found",
		"I could touch the sand. I was now safe."
    };
    srand(time(NULL));
    ran_num = (rand() % 4);
    
    printf("%d\n", ran_num);
    
    if(ran_num == 0)
    {
        for(i = 0 ; i < 11 ; i++)
            printf("%s\n", *(long_words0 + i));
    }
    
    if(ran_num == 1)
    {
        for(i = 0 ; i < 11 ; i++)
            printf("%s\n", *(long_words1 + i));        
    }
    
    if(ran_num == 2)
    {
        for(i = 0 ; i < 11 ; i++)
            printf("%s\n", *(long_words2 + i));    
    }
    
    if(ran_num == 3)
    {
        for(i = 0 ; i < 11 ; i++)
            printf("%s\n", *(long_words3 + i));
    }
}

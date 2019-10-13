#include <stdio.h>
#include <stdlib.h>

// commenting style: intelliSense

/**
 * LinkedList의 Node를 정의합니다
 **/ 
struct listNode {
    /** 
     * Node 내에 들어가는 data를 정의합니다.
     **/
    char data;

    /**
     * LinkedList에서 다음 LinkedList Node의 포인터를 정의합니다.
     **/
    struct listNode *nextPtr;
};

/**
 * struct listNode의 재 정의.
 * data와 nextPtr를 member로 가지고 있습니다.
 * 
 * * data: 현재 노드의 data를 정의합니다.
 * * nextPtr: 다음노드의 포인터를 정의합니다.
 **/
typedef struct listNode ListNode;

/**
 * ListNode 포인터의 재 정의
 **/
typedef ListNode *ListNodePtr;

/* Function Prototypes */

/**
 * 2중 포인터가 필요한 이유. 함수 내에서 ListNodePtr sPtr의 내용을 갱신 하기 위해서임.
 **/

/**
 * 제시한 linkedList에 member를 추가합니다. (sort 됨)
 * 
 * @param sPtr linkedList의 시작 노드의 포인터의 포인터 (2중 포인터)
 * @param value 추가할 node의 data value를 제시합니다.
 **/
void insert( ListNodePtr *sPtr, char value );

/**
 * 제시한 linkedList에서 제시한 member를 data로 가지고 있는 Node의 first-occurance를 제거합니다.
 * 
 * @param sPtr linkedList의 시작 노드 포인터의 포인터 (2중 포인터)
 * @param value 삭제할 node의 data value를 제시합니다.
 * 
 * @return char형으로 반환, 성공한 경우 삭제한 문자 반환, 실패한 경우 0 (= NULL)을 반환 (= falsy value)
 **/
char delete( ListNodePtr *sPtr, char value );

/**
 * 제시한 linkedList가 비어있는지 확인 합니다.
 * 
 * @param sPtr linkedList의 시작 노드 포인터
 * @return int형으로 반환, 비어있는 경우 1 (= truthy value) 반환, 비어있지 않은 경우 0 (= falsy value) 반환.
 **/
int isEmpty( ListNodePtr sPtr );

/**
 * 제시한 linkedList의 내용을 표시합니다.
 * 
 * @param currentPtr 지정한 linkedList의 (부분 또는 전체의) 시작포인터
 **/
void printList( ListNodePtr currentPtr );

/**
 * 사용법을 표시합니다.
 **/
void instructions();

/**
 * 엔트리포인트
 **/
int main() {
    ListNodePtr startPtr = NULL; // linkedList의 첫 노드를 저장할 공간
    int choice; // 사용자의 입력을 저장할 공간 (1-3)
    char item; // 입력 받은 데이터를 저장할 공간
    printf("? "); // 사용자에게 제시할 프롬프트
    scanf("%d", &choice); // 사용자에게서 프롬프트의 input을 받기 위해서

    // input == 3 이라면 이 프로그램을 종료함.
    while (choice != 3) {

        // switch 문을 이용해 입력한 choice에 대해서 case-by-case 검사를 시행
        switch(choice) {

            // 사용자에게 입력을 받고 입력마다 검사 수행
            case 1:
                printf("Enter a character: ");   // 추가할 문자 입력 프롬프트
                scanf("\n%c", &item);  // 유저에게서 입력 받기
                insert(&startPtr, item);  // insert 함수 호출 (Function Prototype에 제시된 내용 참고)
                printList(startPtr);  // list 내용 출력 (Function Prototype에 제시된 내용 참고)
                break;
            case 2:
                // startPtr를 isEmpty function으로 검사
                if (!isEmpty(startPtr)) {
                    printf("Enter character to be deleted: ");  // 삭제할 문자 입력 프롬프트
                    scanf("\n%c", &item);  // 유저에게서 입력 받기

                    // delete function의 성공 여부 확인
                    if (delete(&startPtr, item)) {
                        printf("%c deleted\n", item); // item이 삭제되었는지 메세지 표시
                        printList(startPtr);  // 리스트 표시
                    } else {
                        printf("%c not found. \n\n", item);  // 찾을 수 없었다는 메세지 표시
                    }
                } else {
                    printf("List is empty.\n\n");  // isEmpty function에서 truthy value가 return 되었기에 리스트가 비어있다는 메세지를 표시
                }
                break;
            default:
                printf("Invalid choice\n\n"); // 모든 케이스에 대해서 실패 했기에 invalid choice 라는 것을 표시함.
                instructions();  // 사용법을 표시
                break;
        }

        printf("? ");  // 프롬프트 밖애
        scanf("%d", &choice);
    }

    printf("End of run.\n");  // while 문의 밖에 나온 것을 확인
    return 0;  // Windows의 경우 %errorlevel%, *NIX 시스템의 경우 $? 값을 0으로 리턴하고 애플리케이션을 종료합니다.
}

void instructions() {
    printf("Enter your choice:\n"
    "\t1 to insert an element into the list.\n"
    "\t2 to delete an element from the list\n"
    "\t3 to end.\n");  // 사용법을 출력합니다.
}

void insert(ListNodePtr *sPtr, char value) {

    // 새로운 노드를 저장할 포인터 변수 newPtr
    ListNodePtr newPtr;

    // 노드의 전 노드를 저장할 포인터 변수 previousPtr
    ListNodePtr previousPtr;

    // insert되는 노드의 뒤에 나와야하는 node (아래에서 while-loop으로 진행됨.)
    ListNodePtr currentPtr;

    // heap 영역에 ListNode 사이즈의 메모리 공간을 동적 할당함.
    newPtr = (ListNodePtr)malloc(sizeof(ListNode));

    // 할당에 실패했는 지 확인 
    if (newPtr != NULL) {

        // newPtr의 data를 인수 value로 치환
        newPtr->data = value;

        // 다음 포인터는 NULL로 초기화 (Garbage value가 들어있는 경우가 많으므로 초기화 해야 함)
        newPtr->nextPtr = NULL;

        // previousPtr를 NULL로 초기화
        previousPtr = NULL;

        // while loop를 돌리기 위해 인수로 받은 첫 포인터의 첫 포인터를 currentPtr에 저장
        currentPtr = *sPtr;

        // 인수로 받은 첫 포인터가 NULL이거나 인수로 받은 value 보다 현재 포인터의 data가 더 큰경우 while에서 탈출
        while (currentPtr != NULL && value > currentPtr->data) {

            // 이전 포인터에 현재 포인터 대입
            previousPtr = currentPtr;

            // 현재 포인터에 다음 포인터 대입
            currentPtr = currentPtr->nextPtr;
        }

        // previous node가 존재하지 않는 경우
        if (previousPtr == NULL) {

            // 노드의 시작으로 제시한 것을 현재 노드의 다음 포인터로 저장.
            newPtr->nextPtr = *sPtr;

            // 새로 생성한 노드를 첫 포인터로 업데이트 함: 이것 때문에 2중 포인터로 인수를 받은 것
            *sPtr = newPtr;
        } else {

            // previous Node의 다음 포인터를 새로운 노드의 포인터로 지정.
            previousPtr->nextPtr = newPtr;

            // 새로운 포인터의 다음 포인터를 currentPtr로 정의
            newPtr->nextPtr = currentPtr;
        }

    } else {
        // 메모리 할당 실패를 유저에게 알림.
        printf("%c not inserted. No memory available.\n", value);
    }
}

char delete(ListNodePtr *sPtr, char value) {
    
    // 지워야 할 Node
    ListNodePtr currentPtr;
    // 지워야 할 Node 이전의 Node
    ListNodePtr previousPtr;
    // free 이전에 임시로 저장하는 포인터 변수
    ListNodePtr tempPtr;

    // 맨 처음 Node라면
    if (value == (*sPtr)->data) {
        // 맨 첫 포인터에 저장하고
        tempPtr = *sPtr;
        // 처음 포인터를 다음 포인터로 지정한다음
        *sPtr = (*sPtr)->nextPtr;
        // heap에서 free
        free(tempPtr);
        // value 리턴
        return value;
    } else {
        // 이전 포인터 확인
        previousPtr = *sPtr;
        // 현재 포인터는 이전포인터의 다음 포인터
        currentPtr = (*sPtr)->nextPtr;

        // node의 data가 valued 이거나 linkedList의 끝까지 반복
        while (currentPtr != NULL && currentPtr->data != value) {

            // 이전 노드의 포인터를 현재 포인터로
            previousPtr = currentPtr;

            // 현재 포인터를 다음 포인터로
            currentPtr = currentPtr->nextPtr;
        }

        // 만약 현재포인터가 존재한다면
        if (currentPtr != NULL) {

            // tempPtr에 복사
            tempPtr = currentPtr;

            // 기존 Node의 다음포인터를 현재 포인터의 다음 포인터로 설정
            previousPtr->nextPtr = currentPtr->nextPtr;

            // 임시포인터를 heap에서 free 함
            free(tempPtr);

            // value를 리턴
            return value;
        }
    }

    // 찾지 못했다면, NULL = 0 (falsy value) 리턴
    return '\0';
}


int isEmpty( ListNodePtr sPtr ) { return sPtr == NULL; /* 인수로 받은 포인터가 NULL인지 확인 */ };

void printList(ListNodePtr currentPtr) {
    // 첫 포인터가 NULL 이면
    if (currentPtr == NULL) {
        printf("List is empty.\n\n"); // 리스트가 텅텅 비었다고 메세지
    } else {
        printf("The list is:\n"); // 리스트가 비어있지 않다면, The list is: 라고 표시

        // linkedList의 끝까지
        while(currentPtr != NULL) {
            // 현재 포인터의 데이터 를 표시하고 -> 를 표시
            printf("%c ->", currentPtr->data);

            // 현재 포인터를 다음 포인터로
            currentPtr = currentPtr->nextPtr;
        }

        // NULL 표시
        printf("NULL\n\n");
    }
}

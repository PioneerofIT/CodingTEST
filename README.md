## 61. 특정 수 만들기

> **문제 유형:** DFS (Depth-First Search)  
> **핵심 개념:** 부분집합 탐색, 가지치기, 재귀적 탐색  

### 🔗 참고 링크  
📎 [Velog 글 보러가기](https://velog.io/@rjsgml3736/DFS-%EA%B0%9C%EB%85%90%EC%A0%95%EB%A6%AC-%ED%8A%B9%EC%A0%95-%EC%88%98-%EB%A7%8C%EB%93%A4%EA%B8%B0-%EC%B0%B8%EC%97%AC%ED%95%98%EC%A7%80-%EC%95%8A%EB%8A%94-%EA%B0%80%EC%A7%80%EB%A5%BC-%EC%A7%81%EC%A0%91-%EB%96%A0%EC%98%AC%EB%A6%B0-%EC%88%9C%EA%B0%84)



1. 인접리스트 벡터 (블로그 정리 예정)
$ vector<int> vArr[3] : 벡터 객체 3개를 만듬 배열 X

vArr[0].push_back(1);
vArr[0].push_back(2);
vArr[0].push_back(3);

vArr[1].push_back(4);
vArr[1].push_back(5);
vArr[1].push_back(6);

vArr[0][1] --> 1
vArr[0][2] --> 2
vArr[0][3] --> 1

vArr[1][0] --> 4
vArr[1][1] --> 5
vArr[1][2] --> 1

$ vector<pair<int, int> > graph[3];

graph[1].push_back({3,5});
graph[1].push_back({4,7});

graph[2].push_back(make_pair(7,7));

graph[1][0].frist --> 3
graph[1][0].second --> 5

## 🧮 [개념 정리] 우선순위 큐 (Priority Queue)
### 🔗 참고 링크
[https://velog.io/@rjsgml3736/우선순위-큐-최대-힙-최대-힙]

71.
/*“큐에 넣은 뒤 확인” 하면
큐에 넣고 나서 확인하면,
이미 다음 루프에서 꺼낼 때까지 기다려야 해요.
즉, 한 번 더 불필요하게 큐에 넣었다가 pop하는 과정이 생김.
→ 결과는 같지만 비효율적 (한 스텝 늦어짐)*/


75. 정리요망

## 🧮 [개념 정리] DisJoint Set 자료구조 (Union&Find)
### 🔗 참고 링크
[https://velog.io/@rjsgml3736/Disjoint-Set-서로소-집합-Union-Find-정리]

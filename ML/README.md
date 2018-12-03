## ML의 기본적인 알고리즘
1. Linear regression, Logistic regression(classfication)
2. NN, CNN, RNN (Deep Learning, 위 둘을 기반)

==> Tensorflow를 갖고 실제 문제를 풀어봄

# Basic Concept

## ML
1. Limitations of explicit programming
  ==> 데이터를 보고 학습하는 능력을 가진 프로그램 (개발자가 일일이 할 필요 없음)

2. 데이터 학습을 위해 데이터가 필요함 -> 학습하는 방법에 따른 분류
    1. supervised learning
        - 레이블들이 정해진 데이터 = training set
    2. unsupervised learning
        - 레이블을 일일일 줄 수 없는 경우 ex) google news grouping / word clutering
            - 데이터를 보고 스스로 학습

    ==> supervised learning을 다룰 것임

3. supervised learning
    1. image labeling / email spam filter / predicting exam score
    2. Training data set
        - 이미 정답이 정해져있음(label = Y) / X_test = [9, 3, 6] -(ML)-Y
    3. AlphaGo
        -
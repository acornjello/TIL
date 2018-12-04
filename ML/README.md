- 1일차 -
# ML의 기본적인 알고리즘
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
        - 이미 정답이 정해져있음(label = Y) / X_test = [9, 3, 6] -(ML)
    3. supervised learning의 type
        1. Regression
            - predicting final exam score(0~100) based on time spent
                
        2. binary classification
            - pass/non-pass based on time spent
        3. multi-label classification
            - letter grade (A,B,C,D and F) based on time spent

        + x(hours) y(score) ==> train regression
        +  10       90 P A     ==> 7hours? ==> 75
        +   9       80 P B
        +   3       50 F C
        +   2       30 F D
    
    
    
// 2일차
>>> 설치
>>> anaconda 5.3.1 설치 후 conda install python=3.6.7로 변경
>>> pip install --upgrade tensorflow

#TensorFlow
: google에서 만든 machine inteligence를 위한 opensource library ==> data flow graph를 이용하여 numerical computation(계산)을 한다.

1. data flow graph
    - node(operation) & edge(data(tensor))
// ex1
2. tensorflow mechanics
    1. 그래프를 빌드
    2. session.run이라는 것을 통해 그래프를 실행
    3. 그래프 업데이트..



#Linear Regression

## Hypothesis와 Cost
-supervised learning을 할 때에 regression모델이 train을 하면,
어떤학생이 7시간을 공부했는데 몇점을 받을 수 있을까 모델에 물어볼때 학습된 데이터를 기반으로 65점을 예측

- data set
X = [1, 2, 3] (입력)
Y = [1, 2, 3] (결과)

- regression모델을 사용하고싶으면 가설을 만드는 것이 좋음
- linear하다라고 가설했을 때  ==> linear regression
- ex) 집의 크기가 클수록 가격상승, 훈련 많이할 수록 좋은 체력 등

1. (Linear) Hypothesis
    1. H(x) = Wx+b // H(x) 가설, W와 b에따라 그래프 모양 달라짐
    2. which hypothesis is better? ==> which W and b is better?
    3. 가설에 나타내는 점과 실제 데이터 값의 차이룰 계산 --> cost function
    4. Cost function
        = (H(x)-y)^2 (차이가 양수 음수 차이 없이 하기 위해)
        => cost = (1/m) ( simga(i=1~m) (H(x_i - y_i)^2) )
        // m : 학습데이터의 개수
        // m 개만큼 예측한 값 - 실제값을 제곱한 것을 더함
    5. cost(W, b) = 위와 동일
    6. Goal : minimize cost
        - minimizeCost(W, b)


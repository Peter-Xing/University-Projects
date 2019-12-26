
clear;
clc;
[Data,Label] = xlsread("wdbc_data.csv");
%make y_train and y_test, convert label into +/- 1 first
% M -> -1,  B -> 1
N = size(Label,1);
y = zeros(N,1);
L = cell2mat(Label);
for i = 1:N
    if (L(i)=='M')
        y(i)=-1;
    else
        y(i)=1;
    end
end
y_train = y(1:300); % actual output 
y_test = y(301:end); % actual output
%make x_train and x_test, only contain the last 30 features
x_train = zeros(300,30);
x_test = zeros(269,30);
X = zeros(569,30);
for i=1:300
    for j = 1:30
        x_train(i,j) = Data(i,j+2);
    end
end
for i=1:269
    for j = 1:30
        x_test(i,j) = Data(i+300,j+2);
    end
end
for i = 1:569
    for j=1:30
        X(i,j) = Data(i,j+2);
    end
end
%initialize some variables
T=30; % arbitrary number of rounds
D = zeros(300,1)+1/300; % initial Distribution of weights of all training data points
alpha = zeros(T,1); % stores weight of each classifer in each round
er_train = zeros(T,1); % training error of strong classifier in each round
er_test = zeros(T,1); % testing error of strong classifier in each round
er_t = zeros(T,1); % stores each round's weak classifier's training error
h_train = zeros(300,1); % predicted output in each round
h_test = zeros(269,1); % predicted output in each round
H_strong = zeros(300,1); %strong classifier
H_strong2 = zeros(269,1); % for testing data set
H_tr = zeros(300,1); % the output of strong classifier in training set
H_te = zeros(269,1); % the output of strong classifier in testing set

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% we start doing the weak learner, the decision stump
for t = 1:T
    % in each round, we need a vector for all rules 
    % and a vector to store the corresponding misclassification error
    Stump = zeros(30,1); % stores threshold value 
    % the row number is the the feature's index, 
    % if the feature > threshold in it, y = 1 ?
    error = zeros(30,1); % stores misclassification error Lfor each stump in this round
    % we will use the least error to put in er_train
    Lab = zeros(30,1); % Lab stores the 1 or -1, meaning when value greater than threshold
    % the output label will be corresponding +/- 1
    for i = 1:30
        
        [xsorted,l] = sort(x_train(:,i)); % ascending 
        lr = l(end:-1:1); % descending

        score_left  = cumsum(D(l).*y_train(l)); % left to right sums
        score_right = cumsum(D(lr).*y_train(lr));  % right to left sums
        score = -score_left(1:end-1) + score_right(end-1:-1:1);
        
        Id = find( xsorted(1:end-1)<xsorted(2:end) );
        if (size(Id,1)>0)
            [maxscore,ind] = max( abs(score(Id)) ); % maximum weighted agreement
            ind = Id(ind(1));
            werr = 0.5-0.5*maxscore; 
            x0   = (xsorted(ind)+xsorted(ind+1))/2; % threshold 
            si   = sign(score(ind)); % direction of -1 -> 1 change
        else
            werr = 0.5;
            x0=0;
            si=1;
        end
        %stores error of each feature in error vector
        error(i) = werr;
        %stores threhold value of the feature in Stump
        Stump(i) = x0;
        Lab(i) = si; % stores the label when value > x0
        
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % we get the three values for the best classifier chosen in this round
    bestInd = find(error==min(error)); % the best decision rule's index in Stumpb
    Thresh = Stump(bestInd);% find corresponding feature index and the threshold value
    Labelout = Lab(bestInd); % value > Thresh, output label +/- 1
   
    %get the predicted output labels h_train by this weak classifier
    for i = 1:300
        if (x_train(i,bestInd)>Thresh)
        h_train(i)=Labelout;
        else
            if Labelout==1
                 h_train(i)=-1;
            else
                 h_train(i)=1;
            end
        end
    end
    %get the predicted output labels h_train by this weak classifier
     for i = 1:269
        if (x_test(i,bestInd)>Thresh)
        h_test(i)=Labelout;
        else
            if Labelout==1
                 h_test(i)=-1;
            else
                 h_test(i)=1;
            end
        end
    end
    %get the misclassification error
    errData = find(h_train~=y_train); % the index of the wrong labeled data points
    correctD = find(h_train==y_train);
    err = sum(D(errData,:)); % it is the training error of the weak classifier
    er_t(t) = err;
    
    % get alpha next
    alpha(t) = (1/2)*log((1-err)/(err+1e-9));
    
    % update D
    D(errData) = D(errData)/(2*err+1e-19);
    D(correctD) = D(correctD)/(2*(1-err)+1e-19);

    % update the strong classifier 
     H_strong = H_strong + alpha(t)*h_train;
     H_strong2 = H_strong2 + alpha(t)*h_test;
     
    % get the training and testing error of strong classifer in this round
    H_tr = sign(H_strong);
    errD1 = find(H_tr~=y_train);
    err1 = sum(D(errD1,:)); % it is the training error of strong classifier
    er_train(t) = err1;
    
    H_te = sign(H_strong2);
    err_te = sum(H_te~=y_test)/269;
    er_test(t) = err_te;
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%next we do the plots
x = 1:1:T;
f1 = figure;
plot(x,er_train,'*-r');
  hold on
 plot(x,er_test,'-.b');
  hold off
 legend('training','testing'); 
 xlabel('Number of rounds');
ylabel('error');

f3 = figure;
ClassTreeEns = fitensemble(X,y,'AdaBoostM1',40,'Tree');
rsLoss = resubLoss(ClassTreeEns,'Mode','Cumulative');
plot(rsLoss);
legend('fitensemble'); 
xlabel('Number of rounds');
ylabel('Cumulative error');

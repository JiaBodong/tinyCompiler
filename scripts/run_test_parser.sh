set -x 
submission_file="/chalmers/users/bodong/CompilerProject/lab-group-22"
# cd to test directory, 
# please change the path to the test directory (firt clone the repo)
cd ~/tester
# Run the test 
python3 testing.py $submission_file
# return to the previous directory

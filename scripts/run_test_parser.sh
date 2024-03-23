set -x 
submission_file=$(pwd)
# cd to test directory, 
# please change the path to the test directory (firt clone the repo)
cd ~/project/tester
# Run the test 
python3 testing.py $submission_file
# return to the previous directory
cd -
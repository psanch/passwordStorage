#Usage: python3 createAccount.py <username> <salt> <H(s+pw)>

import sys

filename_logins = 'logins.txt'

def createAccountRecord(args):
	username = args[0]
	salt = args[1]
	hashed = args[2]
	print(username,salt,hashed)
	contents = str(username) + ' ' + str(salt) + ' ' + str(hashed) + '\n'

	fp = open(filename_logins, 'a')
	fp.write(contents)
	fp.close()


def main(argv):
	if(len(argv) != 4):
		print('Incorrect argument count')

	createAccountRecord(argv[1:])

main(["","psanchezmunoz","ffff","ffff"])
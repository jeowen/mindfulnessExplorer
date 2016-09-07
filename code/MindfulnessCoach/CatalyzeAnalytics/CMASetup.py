#!/usr/bin/python
import requests
import json
from requests.adapters import HTTPAdapter
from requests.packages.urllib3.poolmanager import PoolManager
import ssl
import sys
import getopt

class MyAdapter(HTTPAdapter):
    def init_poolmanager(self, connections, maxsize, block=False):
        self.poolmanager = PoolManager(num_pools=connections,
                                       maxsize=maxsize,
                                       block=block,
                                       ssl_version=ssl.PROTOCOL_TLSv1)

def usage():
	print('''
Catalyze Mobile Analytics Setup Script Usage

python CMASetup.py --username myusername@email.com --password myP@ssw0rd --appId 185bff27-a5b6-410e-bee3-71db20f51617 --apiKey 5b7a544d-261e-48f6-b254-792d6efa3722
''')

username = None
password = None
app_id = None
api_key = None

try:
	opts, args = getopt.getopt(sys.argv[1:], "u:p:a:k:", ["username=", "password=", "appId=", "apiKey="])
except getopt.GetoptError:
	usage()
	sys.exit(2)

for opt, arg in opts:
	if opt in ('-u', '--username'):
		username = arg
	elif opt in ('-p', '--password'):
		password = arg
	elif opt in ('-a', '--appId'):
		app_id = arg
	elif opt in ('-k', '--apiKey'):
		api_key = arg

if not username or not password or not app_id or not api_key:
	print("\nusername, password, app_id, and api_key are required parameters\n")
	usage()
	sys.exit(2)

# Script to setup custom classes for Catalyze Mobile Analytics

base_url = "https://api.catalyze.io"

headers = {'X-Api-Key': '32a384f5-5d11-4214-812e-b35ced9af4d7', 'Content-Type': 'application/json', 'Accept': 'application/json'}

s = requests.Session()
s.mount('https://', MyAdapter())

# login to the dashboard
route = '{}/v2/auth/signin'.format(base_url)
data = {'username': username, 'password': password}
r = s.post(route, data=json.dumps(data), headers=headers)
resp = r.json()
r.raise_for_status()

headers['Authorization'] = 'Bearer {}'.format(resp['sessionToken'])
headers['X-Api-Key'] = api_key

# create the event custom class
route = '{}/v2/classes'.format(base_url)
data = {'name':'event','schema':{'timestamp':'string','sessionId':'string','metadata':'object','userInviteCode':'string','event':'string','appId':'string','subjectId':'string'},'phi':True}
r = s.post(route, data=json.dumps(data), headers=headers)
resp = r.json()
if r.status_code == 400:
	# this custom class might already exist, try and get it to check the schema
	route = '{}/v2/classes/event'.format(base_url)
	r = s.get(route, headers=headers)
	resp = r.json()
	r.raise_for_status()
	assert 'timestamp' in resp, 'Your event class does not have the appropriate columns defined. Missing `timestamp`'
	assert 'sessionId' in resp, 'Your event class does not have the appropriate columns defined. Missing `sessionId`'
	assert 'metadata' in resp, 'Your event class does not have the appropriate columns defined. Missing `metadata`'
	assert 'userInviteCode' in resp, 'Your event class does not have the appropriate columns defined. Missing `userInviteCode`'
	assert 'event' in resp, 'Your event class does not have the appropriate columns defined. Missing `event`'
	assert 'appId' in resp, 'Your event class does not have the appropriate columns defined. Missing `appId`'
	assert 'subjectId' in resp, 'Your event class does not have the appropriate columns defined. Missing `subjectId`'
elif r.status_code != 200:
	r.raise_for_status()

print('\n\nSuccess! Your application is ready to use with Catalyze Mobile Analytics!')

import requests

token = '0c6d19539ec4e6a10b7ee69603cd3ebe'
base_url = 'https://kox947ka1a.execute-api.ap-northeast-2.amazonaws.com/prod/users/start'

headers = {
    'X-Auth-Token' : token,
    'Content-Type' : 'application/json'}
data = '{ "problem": 1 }'
res = requests.post(base_url, headers=headers, data=data)

print(res.status_code)


import requests
import json
url = "https://ap-south-1.aws.data.mongodb-api.com/app/data-esqhb/endpoint/data/v1/action/find"

payload = json.dumps({
    "collection": "Skills",
    "database": "Directed_Graph",
    "dataSource": "mentoring-cluster",
    # "projection": {
    #     "_id" : 1,
    #     # "name" : "Ada",
    #     # "age" : 205
    # }
})

headers = {
  'Content-Type': 'application/json',
  'Access-Control-Request-Headers': '*',
  'api-key': "fd494IJpBGp6VN0sEfdiWaX28KIL5uObRwQc0iSQzZopoqsW3LHHMyqvlgGdcPr3", 
}

response = requests.request("POST", url, headers=headers, data=payload)

print(response.json())

from django.shortcuts import render
from django.http import HttpResponse
from django.http import JsonResponse
from django.http import FileResponse
import pymongo
import csv
import requests
import json


# Create your views here.

def index(request):
    return HttpResponse("Hello, I am working.")

def requestingParentNode(request):
    parentNode = request.GET['name']
    url = "https://ap-south-1.aws.data.mongodb-api.com/app/data-esqhb/endpoint/data/v1/action/find"
    # myclient = pymongo.MongoClient("mongodb+srv://mentor:KNKQDkT_Zi2P.r9@mentoring-cluster.egmyda9.mongodb.net/")
    # mydb = myclient["Skill"]
    # mycol = mydb["Directed_Graph"]

    # a = mycol.find({"name": "Web Development"})
    
    payload = json.dumps({
        "collection": "Skills",
        "database": "Directed_Graph",
        "dataSource": "mentoring-cluster",
        "projection": {
            "_id": 0,
            "name" : 1,
            "children":1, 
        },
        "filter": {
            "name": parentNode
        }
    })

    headers = {
    'Content-Type': 'application/json',
    'Access-Control-Request-Headers': '*',
    'api-key': "fd494IJpBGp6VN0sEfdiWaX28KIL5uObRwQc0iSQzZopoqsW3LHHMyqvlgGdcPr3", 
    }
    # print(parentNode)
    response = requests.request("POST", url, headers=headers, data=payload)
    print(response.json())
    with open("sample.json", "w") as outfile:
        json.dump(response.json()["documents"], outfile)
    # return FileResponse(response.json())
    # return JsonResponse(response.json())
    return HttpResponse(response)  
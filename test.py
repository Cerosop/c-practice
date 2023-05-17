from sanic import Sanic
from sanic.response import json

app = Sanic("MyHelloworldapp")

@app.route('/')
async def test(request):
    return json({'helo': 'world'})

if __name__ == '__main__':
    app.run(debug=True)  
from flask import Flask, render_template, request, jsonify
import subprocess
import os

app = Flask(__name__, template_folder='.', static_folder='.')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/run-benchmark', methods=['POST'])
def run_benchmark():
    data = request.json
    algo = data.get('algorithm')
    size = data.get('size')

    # Path to compiled C++ binary
    binary_path = os.path.abspath('output/benchmark')

    # Execute C++ program with arguments: algorithm and input size
    try:
        result = subprocess.run([binary_path, algo, str(size)], capture_output=True, text=True, check=True)
        output_str = result.stdout.strip()
        
        # Parse output line as json or return raw text
        import json
        res_json = json.loads(output_str)
        return jsonify(res_json)
    except Exception as e:
        return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True, port=5000)
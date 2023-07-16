from flask import Flask, request, redirect, render_template, url_for
from flask_mysqldb import MySQL

app = Flask(__name__)

# A instalação do flask e bibliotecas para desenvolvimento do backend ocorreram perfeitamente. 
# A instalação do 'docker/imagens' via compose.yml ocorreram perfeitamente tbm, porem 
# não conseguimos fazer a ligação entre o backend e docker. 
# Tentamos varios ip's diferentes outros tipos de codigos, porem sem exito.
# Ai resolvi utilizar o banco de dados de forma local, utilizando 'wampserver' que já tenho familiaridade.
# Referido banco de dados e tabelas relacionais estão na pasta db.

app.config['MYSQL_HOST'] = '127.0.0.1'  #10.0.0.101:9080
#app.config['MYSQL_PORT'] = '3307'
app.config['MYSQL_USER'] = 'root'
app.config['MYSQL_PASSWORD'] = ''
app.config['MYSQL_DB'] = 'mydb'
mysql = MySQL(app)


#INDEX
@app.route('/')
def index():
    return redirect('/alunos')

#CRUD aluno###################################################
###INSERT
@app.route('/alunos', methods= ['GET', 'POST'])
def insert_alunos():
    if request.method == "POST":
        details = request.form
        name = details['name']
        matricula = details['matricula']
        cpf = details['cpf']
        idResp = details['responsavel']

        conn = mysql.connection.cursor()
        #idResp = conn.execute("SELECT idResponsavel FROM responsavel WHERE nome ='" + responsavel + "'")
        conn.execute("INSERT INTO aluno (matricula, nome, cpf, idResponsavel) VALUES(%s, %s, %s, %s)", (matricula, name, cpf, idResp))
        mysql.connection.commit()
        conn.close()
        return 'cadastrado!'
    return render_template('insert_alunos.html')

###SELECT
@app.route('/alunos/select_alunos')
def select_alunos():
    conn = mysql.connection.cursor()  
    result = conn.execute("SELECT * FROM aluno")
    if result > 0:
        details = conn.fetchall()
        return render_template('select_alunos.html', details=details)

###DELETE
@app.route('/alunos/delete_alunos', methods= ['GET', 'POST'])
def delete_alunos():
    if request.method == 'POST':
        details = request.form
        name = details['name']
        
        conn = mysql.connection.cursor()
        if conn.execute("DELETE FROM aluno WHERE nome ='" + name + "'"):
            mysql.connection.commit()
            conn.close()
            return 'deletado!'
        else:
            return 'nao deletado!'    
    return render_template('delete_alunos.html')

###UPDATE
@app.route('/alunos/update_alunos', methods= ['GET', 'POST'])
def update_alunos():
    if request.method == 'POST':
        details = request.form
        name = details['name']
        matricula = details['matricula']
        cpf = details['cpf']
        
        conn = mysql.connection.cursor()
        #idAluno = conn.execute("SELECT idAluno FROM aluno WHERE cpf ='" + cpf + "'")
        if conn.execute("UPDATE aluno SET matricula = %s, nome = %s WHERE cpf = %s", (matricula, name, cpf)):
            mysql.connection.commit()
            conn.close()
            return 'alterado!'
        else:
            return 'nao alterado!'    
    return render_template('update_alunos.html')


#CRUD responsavel###################################################
###INSERT
@app.route('/responsavel', methods= ['GET', 'POST'])
def insert_responsavel():
    if request.method == "POST":
        details = request.form
        name = details['name']
        email = details['email']
        cpf = details['cpf']

        conn = mysql.connection.cursor()
        conn.execute("INSERT INTO responsavel (nome, email, cpf) VALUES(%s, %s, %s)", (name, email, cpf))
        mysql.connection.commit()
        conn.close()
        return 'cadastrado!'
    return render_template('insert_responsavel.html')

###SELECT
@app.route('/responsavel/select_responsavel')
def select_responsavel():
    conn = mysql.connection.cursor()
    result = conn.execute("SELECT * FROM responsavel")
    if result > 0:
        details = conn.fetchall()
        return render_template('select_responsavel.html', details=details)

###DELETE
@app.route('/responsavel/delete_responsavel', methods= ['GET', 'POST'])
def delete_responsavel():
    if request.method == 'POST':
        details = request.form
        name = details['name']
        
        conn = mysql.connection.cursor()
        if conn.execute("DELETE FROM responsavel WHERE nome ='" + name + "'"):
            mysql.connection.commit()
            conn.close()
            return 'deletado!'
        else:
            return 'nao deletado!'    
    return render_template('delete_responsavel.html')

###UPDATE
@app.route('/responsavel/update_responsavel', methods= ['GET', 'POST'])
def update_responsavel():
    if request.method == 'POST':
        details = request.form
        name = details['name']
        email = details['email']
        cpf = details['cpf']
        
        conn = mysql.connection.cursor()
        #idResp = conn.execute("SELECT idResponsavel FROM responsavel WHERE cpf ='" + cpf + "'")
        if conn.execute("UPDATE responsavel SET nome = %s, email = %s WHERE cpf = %s", (name, email, cpf)):
            mysql.connection.commit()
            conn.close()
            return 'alterado!'
        else:
            return 'nao alterado!'    
    return render_template('update_responsavel.html')


#CRUD nutricionista###################################################
###INSERT
@app.route('/nutricionista', methods= ['GET', 'POST'])
def insert_nutricionista():
    if request.method == "POST":
        details = request.form
        name = details['name']
        email = details['email']
        registro = details['registro']
        cpf = details['cpf']

        conn = mysql.connection.cursor()
        conn.execute("INSERT INTO nutricionista (nome, email, registro, cpf) VALUES(%s, %s, %s, %s)", (name, email, registro, cpf))
        mysql.connection.commit()
        conn.close()
        return 'cadastrado!'
    return render_template('insert_nutricionista.html')

###SELECT
@app.route('/nutricionista/select_nutricionista')
def select_nutricionista():
    conn = mysql.connection.cursor()
    result = conn.execute("SELECT * FROM nutricionista")
    if result > 0:
        details = conn.fetchall()
        return render_template('select_nutricionista.html', details=details)

###DELETE
@app.route('/nutricionista/delete_nutricionista', methods= ['GET', 'POST'])
def delete_nutricionista():
    if request.method == 'POST':
        details = request.form
        name = details['name']
        
        conn = mysql.connection.cursor()
        if conn.execute("DELETE FROM nutricionista WHERE nome ='" + name + "'"):
            mysql.connection.commit()
            conn.close()
            return 'deletado!'
        else:
            return 'nao deletado!'    
    return render_template('delete_nutricionista.html')

###UPDATE
@app.route('/nutricionista/update_nutricionista', methods= ['GET', 'POST'])
def update_nutricionista():
    if request.method == 'POST':
        details = request.form
        name = details['name']
        email = details['email']
        registro = details['registro']
        cpf = details['cpf']
        
        conn = mysql.connection.cursor()
        #idNutri = conn.execute("SELECT idNutricionista FROM nutricionista WHERE cpf ='" + cpf + "'")
        if conn.execute("UPDATE nutricionista SET nome = %s, email = %s, registro = %s WHERE cpf = %s", (name, email, registro, cpf)):
            mysql.connection.commit()
            conn.close()
            return 'alterado!'
        else:
            return 'nao alterado!'    
    return render_template('update_nutricionista.html')


#CRUD registro_dia###################################################
###INSERT
@app.route('/registro_dia', methods= ['GET', 'POST'])
def insert_registro_dia():
    if request.method == "POST":
        details = request.form
        carboidrato = details['carbo']
        proteina = details['proteina']
        salada = details['salada']
        sobremesa = details['sobremesa']
        idNutri = details[ 'nutri_do_dia']
        
        conn = mysql.connection.cursor()
        #idNutri = conn.execute("SELECT idNutricionista FROM nutricionista WHERE nome ='" + nutri_do_dia + "'")
        conn.execute("INSERT INTO registro_dia (carboidrato, proteina, salada, sobremesa, idNutricionista) VALUES(%s, %s, %s, %s, %s)", (carboidrato, proteina, salada, sobremesa, idNutri))
        mysql.connection.commit()
        conn.close()
        return 'cadastrado!'
    return render_template('insert_registro_dia.html')

###SELECT
@app.route('/registro_dia/select_registro_dia')
def select_registro_dia():
    conn = mysql.connection.cursor()  
    result = conn.execute("SELECT * FROM registro_dia")
    if result > 0:
        details = conn.fetchall()
        return render_template('select_registro_dia.html', details=details)

###DELETE
@app.route('/registro_dia/delete_registro_dia', methods= ['GET', 'POST'])
def delete_registro_dia():
    if request.method == 'POST':
        details = request.form
        idRegi = details['idRegi']
        
        conn = mysql.connection.cursor()
        if conn.execute("DELETE FROM registro_dia WHERE idRegistro ='" + idRegi + "'"):
            mysql.connection.commit()
            conn.close()
            return 'deletado!'
        else:
            return 'nao deletado!'    
    return render_template('delete_registro_dia.html')

###UPDATE
@app.route('/registro_dia/update_registro_dia', methods= ['GET', 'POST'])
def update_registro_dia():
    if request.method == 'POST':
        details = request.form
        carboidrato = details['carbo']
        proteina = details['proteina']
        salada = details['salada']
        sobremesa = details[ 'sobremesa']
        idRegi = details ['idRegi']
        
        conn = mysql.connection.cursor()
        if conn.execute("UPDATE registro_dia SET carboidrato = %s, proteina = %s, salada = %s, sobremesa = %s WHERE idRegistro = %s", (carboidrato, proteina, salada, sobremesa, idRegi)):
            mysql.connection.commit()
            conn.close()
            return 'alterado!'
        else:
            return 'nao alterado!'    
    return render_template('update_registro_dia.html')


#CRUD observacao_aluno###################################################
###INSERT
@app.route('/observacao_aluno', methods= ['GET', 'POST'])
def insert_observacao_aluno():
    if request.method == "POST":
        details = request.form
        obs = details['obs']
        data = details['data']
        idAluno = details['aluno']
        idNutri = details[ 'nutri']
        
        conn = mysql.connection.cursor()
        #idAluno = conn.execute("SELECT idAluno FROM aluno WHERE nome LIKE 'Isa Silva%'")
        #idNutri = conn.execute("SELECT idNutricionista FROM nutricionista WHERE nome ='" + nomeNutri + "'")
        conn.execute("INSERT INTO observacao_aluno (obs, dataDia, idAluno, idNutricionista) VALUES(%s, %s, %s, %s)", (obs, data, idAluno, idNutri))
        mysql.connection.commit()
        conn.close()
        return 'cadastrado!'
    return render_template('insert_observacao_aluno.html')

###SELECT
@app.route('/observacao_aluno/select_observacao_aluno')
def select_observacao_aluno():
    conn = mysql.connection.cursor()  
    result = conn.execute("SELECT * FROM observacao_aluno")
    if result > 0:
        details = conn.fetchall()
        return render_template('select_observacao_aluno.html', details=details)

###DELETE
@app.route('/observacao_aluno/delete_observacao_aluno', methods= ['GET', 'POST'])
def delete_observacao_dia():
    if request.method == 'POST':
        details = request.form
        idObs = details['idObs']
        
        conn = mysql.connection.cursor()
        if conn.execute("DELETE FROM observacao_aluno WHERE idObservacao ='" + idObs + "'"):
            mysql.connection.commit()
            conn.close()
            return 'deletado!' 
        else:
            return 'nao deletado!'           
    return render_template('delete_observacao_aluno.html')

###UPDATE
@app.route('/observacao_aluno/update_observacao_aluno', methods= ['GET', 'POST'])
def update_observacao_aluno():
    if request.method == 'POST':
        details = request.form
        idObs = details['idObs']
        obs = details['obs']
        data = details['data']
        
        conn = mysql.connection.cursor()
        if conn.execute("UPDATE observacao_aluno SET obs = %s, dataDia = %s WHERE idObservacao = %s", (obs, data, idObs)):
            mysql.connection.commit()
            conn.close()
            return 'alterado!'
        else:
            return 'nao alterado!'    
    return render_template('update_observacao_aluno.html')


if __name__ == '__main__':
    app.debug = True
    app.run()
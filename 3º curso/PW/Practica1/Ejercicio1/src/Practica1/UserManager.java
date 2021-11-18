package Practica1;
import java.util.ArrayList;
import java.io.*;

/**
 * Esta clase se encarga del inicio de sesión o de registrarse. También guarda los datos en un fichero.
 * @author José Ángel Dorado
 * @version openjdk 11.0.11 2021-04-20
*/
public class UserManager {
	
	private ArrayList<User> listaUser = new ArrayList<User>();
	private static UserManager instancia = null;
	public static UserManager getUserManager() {
		if(instancia == null) {
			instancia = new UserManager();
		}
		return instancia;
	}
	
	/**
	 * Esta función se encarga de leer los datos del usuario del fichero
	 * @return La lista de los datos de un usuario
	 */
	public ArrayList <User> leerFich() {
		File fichero = null;
    	FileReader fr = null;
    	BufferedReader br = null;
    	
    	try {
    		//Apertura del fichero
    		fichero = new File ("/home/pablo/eclipse-workspace/Practica1/src/Practica1/Usuarios.txt");
    		fr = new FileReader (fichero);
    		br = new BufferedReader (fr);
    		
    		String linea;
    		while((linea = br.readLine())!=null) {

				User usuario1 = new User();
				linea = br.readLine();
						
            	//Nombre
            	usuario1.setNombre(linea);
            	//Apellidos
            	usuario1.setApellidos(br.readLine());
            	//Email
            	usuario1.setEmail(br.readLine());
            	//Username
            	usuario1.setUsername(br.readLine());
            	//Password
            	usuario1.setPassword(br.readLine());

				listaUser.add(usuario1);
				
            }
    	}

    	catch(Exception e) {
			e.printStackTrace();
		}finally {
			try{
				if(null != fr) {
					fr.close();
				}
			}catch (Exception e2) {
				e2.printStackTrace();
			}
		}
    	return listaUser;
	}

	
	/**
	 * Esta función se encarga de escribir en el fichero los datos de los usuarios cuando se registran
	 */
	public void escribirFich() {

		FileWriter fichero = null;
		PrintWriter pw = null;
		try 
		{
			fichero = new FileWriter("/home/pablo/eclipse-workspace/Practica1/src/Practica1/Usuarios.txt");
			pw = new PrintWriter(fichero);		
			for(int i=0;i<listaUser.size();i++) {
				pw.println("USUARIO "+ (i+1));
				pw.println(listaUser.get(i).getNombre());
				pw.println(listaUser.get(i).getApellidos());
				pw.println(listaUser.get(i).getEmail());
				pw.println(listaUser.get(i).getUsername());
				pw.println(listaUser.get(i).getPassword());
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if(null != fichero)
					fichero.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
	}
	
	/**
	 * Esta función es la que se encarga de comprobar si el usuario esta en la lista
	 * @param username El nick del usuario
	 * @param password La contraseña del usuario
	 * @return Devuelve true en el caso de que el usuario este en la lista o false en caso contrario
	 */
	public boolean login(String username, String password) {
		//Ver si el usuario esta en la lista
		for(int i = 0; i<this.listaUser.size();i++) {

			if(this.listaUser.get(i).getUsername().equals(username))
			{
				if(this.listaUser.get(i).getPassword().equals(password)) {
					return true;
				}
			}
			
		}
		return false;
	}

	/**
	 * Esta función añade al usuario a la lista y lo escribe en el fichero
	 * @param usuario Son los datos del usuario
	 */
	public void registrar(User usuario) {
		//añadir el usuario a la lista y escribir en el fichero para actualizarlo
		if(usuario != null) {
    		listaUser.add(usuario);
    		escribirFich();    		
    	}
	}
}

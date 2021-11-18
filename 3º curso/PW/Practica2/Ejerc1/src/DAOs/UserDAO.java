package DAOs;

import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;

import Ej2.UserDTO;

/**
 * DAO encargado de gestionar la informacion del usuario en la base de datos
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */

public class UserDAO {

    /** 
     * Esta función añade un nuevo usuario a la base de datos
     * @param user Es un objeto de tipo UserDTO que se quiere introducir a la base de datos
     * @throws IOException Señala que se ha producido una excepción de E/S de algún tipo. Esta clase es la clase general de excepciones producidas por operaciones de E/S fallidas o interrumpidas
     */
    public void create(UserDTO user) throws IOException{
        try{
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");            
              connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
              PreparedStatement ps = connection.prepareStatement("INSERT INTO Usuarios values(?,?,?,?,?,?)");

              	ps.setString(1,user.getNombre());
                ps.setString(2,user.getApellidos());
                ps.setString(3,user.getUsername());
                ps.setString(4,user.getPassword());
                ps.setString(5,user.getEmail());
                ps.setString(6,user.getTipo().toString());

                ps.executeUpdate();

                if (ps != null) { 
                    ps.close(); 
                }

                connection.close();
        } catch (Exception e){
            System.out.println(e);
        }
    }

    /** 
     * Esta función devuelve el usuario que coincide con el nick
     * @param nick Es el nombre de usuario que se quiere buscar
     * @return Devuelve un objeto de tipo UserDTO que coincide con el nick pasado cómo parámetro. En caso de que no se encuentre devolveremos NULL
     */
    public UserDTO buscarUsuarioPorUsername(String nick) {
        UserDTO user = new UserDTO();

        try{
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
            Statement statement = connection.createStatement();

            String sqlString = "select u.Nombre, u.Apellidos, u.Username, u.Password, u.Email, u.Tipo from `Usuarios` u where u.username = '" + nick + "'";
            ResultSet rs = statement.executeQuery(sqlString);

            while (rs.next()) {
                user.setNombre(rs.getString("u.Nombre"));
                user.setApellidos(rs.getString("u.Apellidos"));
                user.setUsername(rs.getString("u.Username"));
                user.setPassword(rs.getString("u.Password"));
                user.setEmail(rs.getString("u.Email"));
                user.setTipoAsString(rs.getString("u.Tipo"));                
            }

            if (statement != null) {
                statement.close();
            }

            return user; 
        } catch (Exception e){
            System.out.println(e);
        }

        return null;
    }

    /**
     * Esta función se encarga de devolver de la base de datos el usuario asociado al mail que se recibe cómo parámetro
	 * @param mail Es el correo del usuario que se quiere buscar en la base de datos
	 * @return Devuelve una instancia de usuario asociada al mail que se recibe cómo párametro. Se devuelve un NULL si no se encuentra
	 */
    public UserDTO buscarUsuarioPorCorreo(String mail) {
        UserDTO user = new UserDTO();

        try{
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
            Statement statement = connection.createStatement();

            String sqlString = "select u.Nombre, u.Apellidos, u.Username, u.Password, u.Email, u.tipo from `Usuarios` u where u.Email = '" + mail + "'";
            ResultSet rs = statement.executeQuery(sqlString);

            while (rs.next()) {
            	user.setNombre(rs.getString("u.Nombre"));
                user.setApellidos(rs.getString("u.Apellidos"));
                user.setUsername(rs.getString("u.Username"));
                user.setPassword(rs.getString("u.Password"));
                user.setEmail(rs.getString("u.Email"));
                user.setTipoAsString(rs.getString("u.Tipo"));                

            }

            if (statement != null) {
                statement.close();
            }

            return user;  
        } catch (Exception e){
            System.out.println(e);
        }

        return null;
    }

    /** 
     * Esta función se encarga de devolver en una lista todos los usuarios que se encuentran en la base de datos
     * @return Devuelve la lista de usuarios que se ha encontrado en la base de datos
     */
    public ArrayList<UserDTO> obtenerTodosUsuarios() {    
        ArrayList<UserDTO> ListaUsuarios = new ArrayList<UserDTO>();

        try{
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
            Statement statement = connection.createStatement();

            String sqlString = "SELECT * FROM Usuarios u";
            ResultSet rs = statement.executeQuery(sqlString);

            while (rs.next()) {
                UserDTO user = new UserDTO();
                user.setNombre(rs.getString("u.Nombre"));
                user.setApellidos(rs.getString("u.Apellidos"));
                user.setUsername(rs.getString("u.Username"));
                user.setPassword(rs.getString("u.Password"));
                user.setEmail(rs.getString("u.Email"));
                user.setTipoAsString(rs.getString("u.Tipo"));                
				
                ListaUsuarios.add(user);
            }

            if (statement != null) {
                statement.close();
            }

            return ListaUsuarios;
        } catch (Exception e){
            System.out.println(e);
        }

        return null;
    }

    /** 
     * Esta función se encarga de eliminar un usuario pasado como parámetro de la base de datos
     * @param user Es un objeto de tipo UserDTO que se quiere eliminar de la base de datos
     */
    public void eliminarUsuario(UserDTO user) {
        try {
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");

            PreparedStatement ps = connection.prepareStatement("DELETE FROM Usuarios WHERE Username = ?");

            ps.setString(1, user.getUsername());

            ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /** 
     * Esta función se encarga de sustituir en la base de datos el nombre de una instancia de usuario asociada al nick pasado cómo parámetro por el de newName
     * @param nick Es el nombre de usuario del usuario al que se le quiere cambiar el nombre
     * @param newName Es el nuevo nombre que se le quiere poner al usuario con el id especificado cómo parámetro
     */
    public void actualizarNombre(String nick, String nuevoNombre) {
        try {
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");

            String sql = "UPDATE Usuarios SET Nombre = ? WHERE Username = ?";
            PreparedStatement ps = connection.prepareStatement(sql);

            ps.setString(1, nuevoNombre);
            ps.setString(2, nick);

            ps.executeUpdate();
            ps.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /** 
     * Esta función se encarga de sustituir en la base de datos el apellido de una instancia de usuario asociada al nick pasado cómo parámetro por el de nuevoApellido
     * @param nick Es el nombre de usuario asociado a la instancia de usuario al que se le quiere cambiar el apellido
     * @param nuevoApellido Es el nuevo apellido que se le quiere atribuir a la instancia de usuario especificada en el nick
     */
    public void actualizarApellidos(String nick, String nuevoApellido) {
        try {
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");

            String sql = "UPDATE Usuarios SET Apellidos = ? WHERE Username = ?";
            PreparedStatement ps = connection.prepareStatement(sql);

            ps.setString(1, nuevoApellido);
            ps.setString(2, nick);

            ps.executeUpdate();
            ps.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /** 
     * Esta función se encarga de sustituir en la base de datos el username de una instancia de usuario asociada al nick que tuviera pasado cómo parámetro por el de nuevoNick
     * @param nick Es la id asociada a la instancia de usuario al que se le quiere cambiar el apodo
     * @param nuevoNick Es el nuevo apodo que se le quiere atribuir a la instancia de usuario especificada en el nick
     */
    public void actualizarUsername(String nick, String nuevoNick) {
        try {
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");

            String sql = "UPDATE Usuarios SET Username = ? WHERE Username = ?";
            PreparedStatement ps = connection.prepareStatement(sql);

            ps.setString(1, nuevoNick);
            ps.setString(2, nick);

            ps.executeUpdate();
            ps.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /** 
     * Esta función se encarga de sustituir en la base de datos el correo de una instancia de usuario asociada al username pasado cómo parámetro por el de nuevoEmail
     * @param nick Es la id asociada a la instancia de usuario al que se le quiere cambiar el correo
     * @param nuevoEmail Es el nuevo correo que se le quiere atribuir a la instancia de usuario especificada en el nick
     */
    public void actualizarEmail(String nick, String nuevoEmail) {
        try {
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");

            String sql = "UPDATE Usuarios SET Email = ? WHERE Username = ?";
            PreparedStatement ps = connection.prepareStatement(sql);

            ps.setString(1, nuevoEmail);
            ps.setString(2, nick);

            ps.executeUpdate();
            ps.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
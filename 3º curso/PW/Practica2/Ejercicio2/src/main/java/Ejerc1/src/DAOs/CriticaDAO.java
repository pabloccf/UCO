package Ejerc1.src.DAOs;

import java.sql.*;
import java.util.*;
import Ejerc1.src.Ej2.CriticaDTO;

/**
 * DAO encargado de escribir todas las críticas del sistema en la base de datos
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */

public class CriticaDAO {
    
    /**
     * Es el constructor de la clase CriticaDAO
     */
    public CriticaDAO(){}

    /** 
     * Esta función añadirá una crítica a la base de datos
     * @param critica Es el objeto de tipo CriticaDTO a añadir en la base de datos
     */
    public void crearCritica(CriticaDTO critica) {
        try{
            Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
            PreparedStatement ps = connection.prepareStatement("INSERT INTO `Criticas` values(?,?,?,?,?,?)");

                ps.setString(1, critica.getTitulo());
                ps.setInt(2, critica.getPuntuacion());
                ps.setString(3, critica.getTexto());
                ps.setInt(4, critica.getValoracion());
                ps.setString(5, critica.getOwner());
                ps.setInt(6, critica.getCantidadValoraciones());

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
     * Esta función se encarga de eliminar una critica de la base de datos pasando como parámetro el titulo de la critica 
     * @param titulo Es el título de la crítica que se quiere eliminar de la base de datos
     */
    public void eliminarCritica(String titulo) {
        try {
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");

            PreparedStatement ps = connection.prepareStatement("DELETE FROM Criticas WHERE Titulo = ?");

            ps.setString(1, titulo);

            ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    /** 
     * Esta función se encarga de sustituir en la base de datos la critica antigua que hubiera por la nueva
     * @param critica Es un objeto de tipo CriticaDTO que es la nueva critica del usuario que se quiere introducir
     * @param oldCritica Es un objeto de tipo CriticaDTO que es la antigua critica que se va a reemplazar
     */
    public void actualizarCritica(CriticaDTO critica, CriticaDTO oldCritica) {
        try {
        	Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");

            String sql = "UPDATE Criticas SET Titulo = ?, Puntuacion = ?, Texto = ?, Valoracion = ?, Owner = ?, CantidadValoraciones = ?  WHERE Titulo = ?";
            PreparedStatement ps = connection.prepareStatement(sql);

            ps.setString(1, critica.getTitulo());
            ps.setInt(2, critica.getPuntuacion());
            ps.setString(3, critica.getTexto());
            ps.setInt(4, critica.getValoracion());
            ps.setString(5, critica.getOwner());
            ps.setInt(6, critica.getCantidadValoraciones());
            ps.setString(7, oldCritica.getTitulo());


            ps.executeUpdate();
            ps.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    /** 
	 * Esta función se encarga de buscar y devolver de la base de datos las criticas que coincidan con el titulo pasado como argumento
	 * @param titulo Es el título de la critica a buscar
	 * @return Devuelve un objeto de tipo CriticaDTO si se encuentra y en caso de no encontrar nada devuelve NULL
	 */
	public CriticaDTO obtenerCriticaTitulo(String titulo) {
	    CriticaDTO critica = new CriticaDTO();

	    try{
	        Connection connection = null;
	        Class.forName("com.mysql.jdbc.Driver");
	        connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
	        Statement statement = connection.createStatement();

	        String sqlString = "select c.Titulo, c.Puntuacion, c.Texto, c.Valoracion, c.Owner, c.CantidadValoraciones from `Criticas` c where c.Titulo = '" + titulo + "'";
	        ResultSet rs = statement.executeQuery(sqlString);

	        while (rs.next()) {
	            critica.setTitulo(rs.getString("c.Titulo"));
	            critica.setPuntuacion(rs.getInt("c.Puntuacion"));
	            critica.setTexto(rs.getString("c.Texto"));
	            critica.setValoracion(rs.getInt("c.Valoracion"));
	            critica.setOwner(rs.getString("c.Owner"));
	            critica.setCantidadValoraciones(rs.getInt("c.CantidadValoraciones"));
	        }
	            
	            if (statement != null) {
					statement.close();
				}

	            return critica;
	    } catch (Exception e){
	            System.out.println(e);
	    }

	    return null;
	}
    
	/**
     * Esta función se encarga de devolver una lista con todas las criticas
     * @return Devuelve una lista de criticas con todas las criticas. En el caso de no encontrar las criticas devuelve NULL
     */
    public ArrayList<CriticaDTO> ObtenerTodasCriticas() {        
        ArrayList<CriticaDTO> criticas = new ArrayList<CriticaDTO>();
        
        try{
            Connection connection = null;
            Class.forName("com.mysql.jdbc.Driver");
            connection = (Connection) DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i92ibfep","i92ibfep","PWpaiba");
            Statement statement = connection.createStatement();

            String sqlString = "select c.Titulo, c.Puntuacion, c.Texto, c.Valoracion, c.Owner, c.CantidadValoraciones from `Criticas` c";
            ResultSet rs = statement.executeQuery(sqlString);

            while (rs.next()) {
                CriticaDTO critica = new CriticaDTO();

                critica.setTitulo(rs.getString("c.Titulo"));
                critica.setPuntuacion(rs.getInt("c.Puntuacion"));
                critica.setTexto(rs.getString("c.Texto"));
                critica.setValoracion(rs.getInt("c.Valoracion"));
                critica.setOwner(rs.getString("c.Owner"));
                critica.setCantidadValoraciones(rs.getInt("c.CantidadValoraciones"));
                    
                criticas.add(critica);
            }

            if (statement != null) {
                statement.close();
            }

            return criticas;
        } catch (Exception e){
            System.out.println(e);
        }

        return null; 
    }
}
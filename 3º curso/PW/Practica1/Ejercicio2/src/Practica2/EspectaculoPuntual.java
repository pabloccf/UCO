package Practica2;

public class EspectaculoPuntual extends Espectaculo {
		private String fecha;
		private Integer hora;
		
		public EspectaculoPuntual(String titulo, String descripcion, String categoria, Integer aforo, String Fecha, Integer Hora) {
			super(titulo, descripcion, categoria, aforo);
			this.fecha = Fecha;
			this.hora = Hora;
		}
		
		public String getFecha() {
			return fecha;
		}
		public void setFecha(String fecha) {
			this.fecha = fecha;
		}
		public Integer getHora() {
			return hora;
		}
		public void setHora(Integer hora) {
			this.hora = hora;
		}
		
}

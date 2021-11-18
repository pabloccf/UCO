package Practica2;

public class timeStamp {
		private String hora;
		private String fecha;
		
		public timeStamp(String hora, String fecha) {
			super();
			this.hora = hora;
			this.fecha = fecha;
		}

		public String getHora() {
			return hora;
		}

		public void setHora(String hora) {
			this.hora = hora;
		}

		public String getFecha() {
			return fecha;
		}

		public void setFecha(String fecha) {
			this.fecha = fecha;
		}
		
		public String toString() {
			return hora+";"+fecha;
		}

		public timeStamp(String timeStamp) {
			String[] array = timeStamp.split(";");
			this.hora = array[0];
			this.fecha = array[1];
			
		}
		
		
}

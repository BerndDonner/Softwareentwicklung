import pandas as pd
import plotly.graph_objects as go

# Load CSV data
data = pd.read_csv("data.csv")

# Extract starting points and vector components
x_start = data['u']
y_start = data['v']
z_start = data['w']

# Calculate end points of the arrows
x_end = x_start + data['x']
y_end = y_start + data['y']
z_end = z_start + data['z']

# Create a list of traces (lines for arrows)
arrow_traces = []
for xs, ys, zs, xe, ye, ze in zip(x_start, y_start, z_start, x_end, y_end, z_end):
    arrow_traces.append(
        go.Scatter3d(
            x=[xs, xe],  # Line from start to end
            y=[ys, ye],
            z=[zs, ze],
            mode='lines',
            line=dict(color='blue', width=3),
        )
    )

# Add balls at the end of arrows
arrow_traces.append(
    go.Scatter3d(
        x=x_end,  # Only end points
        y=y_end,
        z=z_end,
        mode='markers',
        marker=dict(size=6, color='red'),
    )
)

# Create the figure
fig = go.Figure(data=arrow_traces)

# Update layout for better visualization
fig.update_layout(
    scene=dict(
        xaxis_title='X Axis',
        yaxis_title='Y Axis',
        zaxis_title='Z Axis',
    ),
    title='3D Vector Arrows'
)

# Show the plot
fig.show()

